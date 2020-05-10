#include <stdio.h>
#include <string.h>

int main()
{
    int a, b, c = 0, len, i, cnt = 0;
    char num[10];

    scanf("%d %d", &a, &b);

    sprintf(num, "%d", a + b);

    len = strlen(num);

    if (num[0] == '-')
    {
        printf("-");
        len--;
        c = 1;
    }

    if (len > 3)
    {
        cnt = 1;
        i = len;
        while ((i -= 3) > 0)
        {
            cnt++;
        }
        cnt--;
    }

    for (i = c; cnt != 0; i++)
    {
        printf("%c", num[i]);
        len--;
        if (len % 3 == 0)
        {
            printf(",");
            cnt--;
        }
    }

    while (len--)
    {
        printf("%c", num[i++]);
    }

    return 0;
}