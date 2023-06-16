#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;

    srand(time(NULL));  /* Initialize the random number generator with current time */

    n = rand();  /* Generate a random number and assign it to variable n */

    printf("The number is: %d\n", n);

    if (n > 0) {
        printf("is positive\n");
    } else if (n == 0) {
        printf("is zero\n");
    } else {
        printf("is negative\n");
    }

    return 0;
}
