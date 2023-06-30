#include <stdio.h>

int int_len(char *s)
{
    int len = 0;
    while (s[len])
        len++;
    return len;
}

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = int_len(n1);
    int len2 = int_len(n2);
    int max_len = (len1 > len2) ? len1 : len2;
    int carry = 0;
    int sum;
    int i, j;

    if (max_len + 1 > size_r)
        return 0;

    r[max_len + 1] = '\0';
    for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--) {
        sum = carry;
        if (i >= 0)
            sum += n1[i] - '0';
        if (j >= 0)
            sum += n2[j] - '0';

        carry = sum / 10;
        sum %= 10;
        r[max_len--] = sum + '0';
    }

    if (carry)
        r[max_len] = carry + '0';
    else
        max_len++;

    for (i = 0; r[max_len]; i++, max_len++)
        r[i] = r[max_len];

    return r;
}
