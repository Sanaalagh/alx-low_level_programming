#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
    int n;
    
    srand(time(NULL)); /* Initialize the random number generator with current time */

    n = rand() % 201 - 100; /* Generate a random number between -100 and 100 */

    printf("The number is: %d\n", n);

    if (n > 0)
    {
        printf("is positive\n");
    }
    else if (n == 0)
    {
        printf("is zero\n");
    }
    else
    {
        printf("is negative\n");
    }

    return (0);
}
