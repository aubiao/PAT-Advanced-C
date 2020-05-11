#include <stdio.h>

int main()
{
    int n, i, j, k, num = 0;
    double A[1001] = {0}, B[1001] = {0}, C[2001] = {0}, nk;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %lf", &k, &nk);
        A[k] = nk;
    }

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %lf", &k, &nk);
        B[k] = nk;
    }

    for (i = 0; i < 1001; i++)
    {
        for (j = 0; j < 1001; j++)
        {
            C[i + j] += A[i] * B[j];
        }
    }

    for (i = 0; i < 2001; i++)
    {
        if (C[i])
            num++;
    }

    printf("%d", num);

    for (i = 2000; i >= 0; i--)
    {
        if (C[i])
        {
            printf(" %d %.1f", i, C[i]);
        }
    }

    return 0;
}