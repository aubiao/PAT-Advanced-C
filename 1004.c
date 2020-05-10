#include <stdio.h>

int main()
{
    int n, m, i, j, num[100][100] = {0}, root, child, k, visit_node[100], node_num_start, node_num_end, node_num, leaf_num;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &root, &k);
        num[root][0] = k;
        for (j = 1; j <= k; j++)
        {
            scanf("%d", &child);
            num[root][j] = child;
        }
    }

    if (n == 1)
    {
        printf("1\n");
    }
    else
    {
        int flag = 0;
        visit_node[0] = 1;
        node_num_start = 0;
        node_num_end = 1;
        node_num = 1;

        while (node_num_start < node_num_end)
        {
            leaf_num = 0;
            for (i = node_num_start; i < node_num_end; i++)
            {
                if (num[visit_node[i]][0] == 0)
                {
                    leaf_num++;
                }
                else
                {
                    for (j = 1; j <= num[visit_node[i]][0]; j++)
                    {
                        visit_node[node_num] = num[visit_node[i]][j];
                        node_num++;
                    }
                }
            }
            node_num_start = node_num_end;
            node_num_end = node_num;
            if (flag == 1)
            {
                printf(" ");
            }
            else
            {
                flag = 1;
            }

            printf("%d", leaf_num);
        }
    }

    return 0;
}