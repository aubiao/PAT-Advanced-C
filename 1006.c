#include <stdio.h>
#include <string.h>

int main()
{
    int n, H, M, S;
    int firsttime = 86400, lasttime = -1, time;
    char name[16], firstname[16], lastname[16];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d", name, &H, &M, &S);

        time = (H * 60 + M) * 60 + S;
        if (time < firsttime)
        {
            firsttime = time;
            strcpy(firstname, name);
        }

        scanf("%d:%d:%d", &H, &M, &S);

        time = (H * 60 + M) * 60 + S;
        if (time > lasttime)
        {
            lasttime = time;
            strcpy(lastname, name);
        }
    }

    printf("%s %s\n", firstname, lastname);

    return 0;
}