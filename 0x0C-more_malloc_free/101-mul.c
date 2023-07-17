#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error\n");
        return 98;
    }

    char *num1 = argv[1];
    char *num2 = argv[2];

    int i, j;
    int len1 = 0, len2 = 0;
    int *result;

    for (i = 0; num1[i] != '\0'; i++)
    {
        if (num1[i] < '0' || num1[i] > '9')
        {
            printf("Error\n");
            return 98;
        }
        len1++;
    }

    for (i = 0; num2[i] != '\0'; i++)
    {
        if (num2[i] < '0' || num2[i] > '9')
        {
            printf("Error\n");
            return 98;
        }
        len2++;
    }

    result = calloc(len1 + len2, sizeof(int));
    if (result == NULL)
    {
        printf("Error\n");
        return 98;
    }

    for (i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        for (j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';

            int sum = result[i + j + 1] + (n1 * n2) + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }

        if (carry > 0)
            result[i + j + 1] += carry;
    }

    int start = 0;
    while (result[start] == 0 && start < len1 + len2 - 1)
        start++;

    for (i = start; i < len1 + len2; i++)
        printf("%d", result[i]);
    printf("\n");

    free(result);

    return 0;
}
