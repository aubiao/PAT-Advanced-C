#include <stdio.h>

int main()
{
    int n, num, i, a = -1, b, sum = -1, start, end, maxsum = 0, first;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);

        if (i == 0)
            first = num;

        if (sum < 0)
        {
            sum = 0;
            start = num;
        }
        sum += num;
        if (sum >= 0)
            end = num;

        if (sum > maxsum || (!sum && !maxsum))
        {
            a = start;
            b = end;
            maxsum = sum;
        }
    }

    if (a == -1)
    {
        printf("0 %d %d\n", first, num);
    }
    else
    {
        printf("%d %d %d\n", maxsum, a, b);
    }

    return 0;
}