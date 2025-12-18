#include "probability.h"

double calculate_probability(int white_count, int red_count) {
    double total = white_count + red_count;

    if (red_count < 2 || total < 2) {
        return 0.0;
    }
    double p1 = (double)red_count / total;
    double p2 = (double)(red_count - 1) / (total - 1);

    return p1 * p2;
}