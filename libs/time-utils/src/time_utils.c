#include "time-utils.h"
#include <time.h>

long date_to_timestamp(char* date)
{
    struct tm tm = {0};

    strptime(date, DATE_TIME_FORMAT, &tm);
     
    tm.tm_hour = 0;
    tm.tm_min  = 0;
    tm.tm_sec  = 0;

    return mktime(&tm);
}

char* timestamp_to_date(long timestamp, char* date, int size)
{
    struct tm *tm = localtime(&timestamp);

    strftime(date, size, DATE_TIME_FORMAT, tm);

    return date;
}
