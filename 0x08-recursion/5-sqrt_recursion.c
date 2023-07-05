#include "main.h"
/**
 * sqrt_recursive - Helper function to calculate the square root recursively
 * @n: The number to find the square root of
 * @guess: The current guess for the square root
 *
 * Return: The square root of n, or -1 if it doesn't have a natural square root
 */
int sqrt_recursive(int n, int guess)
{
if (guess * guess == n) /* Base case: square of guess is equal to n */
return (guess);
if (guess * guess > n) /* Base case: guess exceeds the square root */
return (-1);
return (sqrt_recursive(n, guess + 1));
/* Recursive call to increment guess */
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to find the square root of
 *
 * Return: The square root of n, or -1 if it doesn't have a natural square root
 */
int _sqrt_recursion(int n)
{
if (n < 0) /* Error case: negative number */
return (-1);
return (sqrt_recursive(n, 0));
/* Call the helper function with initial guess 0 */
}
