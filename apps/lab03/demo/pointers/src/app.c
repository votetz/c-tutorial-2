#include "app.h"
/**

 |#|#|#|#|
 ---------
     a_i

         0      1     2       3     4      5     ...
     |######|######|######|######|######|######|######|.....
        a      c       d     e      f       g     h
        |
    |############|

   |######|######|
   |######| |######|

    x32 or x86 2^32 ~ 4Gb

    x64 2^64

 */
int main()
{
    {
        int a = 302;
        int* pa = &a;

        double d = 439.132;
        double* pd = &d;

        //p + n, p - n, ++p, --p, p++, p--, *, -, ==, !=, <, <=, >, >=, p+=n, p-=n
        //NULL
        //nullptr for C++
    }
    printf("-----------------------------------\n");
    {
        int a = 10;

        // &
        int* pa = &a;

        printf("sizeof(p)=%zu\n", sizeof(pa));

        printf("Direct value=%d\n", a);
        printf("Pointer=%p, pointed value=%d\n", pa, *pa);

        *pa = 25;

        printf("Direct value after change via pointer=%d\n", a);
    }

    printf("-----------------------------------\n");
    {
        double a = 12.45;

        // &
        double* pa = &a;

        printf("sizeof(p)=%zu\n", sizeof(pa));

        printf("Direct value=%.3f\n", a);
        printf("Pointer=%p, pointed value=%.3f\n", pa, *pa);
    }

    {
        int a = 23;

        int* pa = &a;

        /**
           23                  ???
         |####|####|####|####|####|
           a
            ^
            |
         |########|
            pa
         */
        printf("Direct value=%d\n", *pa);

        pa += 5;

        printf("Direct value=%d\n", *pa);

        /**
           23                  ???
         |####|####|####|####|####|
           a
                                ^
                                |
                            |########|
                               pa + 5
         */
    }

    return 0;
}
