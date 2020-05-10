#include <stdio.h>

int main()
{
    int sum = 0;
    char c, *eng[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while ((c = getchar()) != '\n')
        sum += c - '0';

    if (sum >= 100)
        printf("%s ", eng[sum / 100]);
    if (sum >= 10)
        printf("%s ", eng[sum % 100 / 10]);
    printf("%s", eng[sum % 10]);

    return 0;
}