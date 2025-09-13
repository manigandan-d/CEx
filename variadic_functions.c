#include <stdio.h>
#include <stdarg.h>

int  sum (int count,...) {
    va_list args;
    va_start(args, count);
    
    int total = 0;

    for(int i=0; i<count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);

    return total;
}

int min(int count,...) {
    va_list args;
    va_start(args, count);
    
    int minimum = va_arg(args, int);

    for(int i=1; i<count; i++) {
        int value = va_arg(args, int);

        if(value < minimum) {
            minimum = value; 
        }
    }

    va_end(args);

    return minimum;
}

int max(int count,...) {
    va_list args;
    va_start(args, count);

    int maximum = va_arg(args, int);

    for(int i=1; i<count; i++) {
        int value = va_arg(args, int);

        if(value > maximum) {
            maximum = value; 
        }
    }

    va_end(args);

    return maximum;
}

int main() {
    printf("Sum = %d\n", sum(5, 10, 20, 30, 40, 50));
    printf("Min = %d\n", min(5, 30, 50, 10, 40, 20));
    printf("Max = %d\n", max(5, 10, 40, 30, 50, 20));

    return 0;
}
