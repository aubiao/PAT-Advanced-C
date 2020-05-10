#include <stdio.h>

int main()
{
    int n, a, i, j, cnt = 0, max = 0;
    double A[1001][2] = {0}, b;

    for (i = 0; i < 2; i++)
    {
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%d %lf", &a, &b);
            A[a][1] += b;
            A[a][0]++;
            if (A[a][0] == 1 && (b >= 0.05 || b <= -0.05))
            {
                cnt++;
            }
            else if (A[a][0] > 1 && A[a][1] < 0.05 && A[a][1] > -0.05)
            {
                cnt--;
            }
            if (max < a)
            {
                max = a;
            }
        }
    }

    printf("%d", cnt);

    for (i = max; i >= 0; i--)
    {
        if (A[i][0] != 0 && (A[i][1] >= 0.05 || A[i][1] <= -0.05))
        {
            printf(" %d %.1lf", i, A[i][1]);
        }
    }

    return 0;
}