#include <stdio.h>

int main()
{
    int n, i, floor, time = 0, floor_now = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &floor);
        if (floor_now < floor)
        {
            time += (floor - floor_now) * 6;
        }
        else
        {
            time += (floor_now - floor) * 4;
        }
        time += 5;
        floor_now = floor;
    }

    printf("%d", time);

    return 0;
}