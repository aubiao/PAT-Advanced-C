#include <stdio.h>

#define inf 99999999

int main()
{
    int n, m, c1, c2, weight[501], dis[501], num[501], e[501][501], w[501], a, b, c, visit[501] = {0}, i, j, k;

    scanf("%d %d %d %d", &n, &m, &c1, &c2);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    for (i = 0; i < 500; i++)
    {
        for (j = 0; j < 500; j++)
        {
            e[i][j] = inf;
        }
    }

    for (i = 0; i < 500; i++)
    {
        dis[i] = inf;
    }

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }

    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;

    for (i = 0; i < n; i++)
    {
        int u = -1, minn = inf;
        for (j = 0; j < n; j++)
        {
            if (!visit[j] && dis[j] < minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1)
            break;
        visit[u] = 1;
        for (k = 0; k < n; k++)
        {
            if (!visit[k] && e[u][k] != inf)
            {
                if (dis[u] + e[u][k] < dis[k])
                {
                    dis[k] = dis[u] + e[u][k];
                    num[k] = num[u];
                    w[k] = w[u] + weight[k];
                }
                else if (dis[u] + e[u][k] == dis[k])
                {
                    num[k] = num[u] + num[k];
                    if (w[u] + weight[k] > w[k])
                    {
                        w[k] = w[u] + weight[k];
                    }
                }
            }
        }
    }

    printf("%d %d", num[c2], w[c2]);

    return 0;
}