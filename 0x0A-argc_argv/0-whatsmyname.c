#include <stdio.h>

int main(int argc, char *argv[])
{
    /* Cast argc to void to silence the unused parameter warning */
    (void)argc;
    printf("%s\n", argv[0]);
    return 0;
}
