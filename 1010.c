#include <stdio.h>
#include <string.h>

#define STRING2NUM(c) ((c) >= '0' && (c) <= '9' ? (c) - '0' : (c) - 'a' + 10)

long long base10(char *s, int radix)
{
    long long sum;
    int n;

    for (sum = 0; *s; s++)
    {
        n = STRING2NUM(*s);
        sum = sum * radix + n;
    }

    return sum;
}

long long is_equal(char *s, long long n1)
{
    long long min, max, i, sum;
    int n;
    char *buf = s;

    for (min = 0; *buf; buf++)
    {
        n = STRING2NUM(*buf);
        if (n > min)
        {
            min = n;
        }
    }

    min++;
    if (min > n1)
    {
        max = min;
    }
    else
    {
        max = n1;
    }

    while (max >= min)
    {
        buf = s;
        i = (min + max) / 2;
        for (sum = 0; *buf; buf++)
        {
            sum = sum * i + STRING2NUM(*buf);
        }
        if (sum == n1)
        {
            return i;
        }
        else if (sum > n1 || sum < 0)
        {
            max = i - 1;
        }
        else
        {
            min = i + 1;
        }
    }
    return 0;
}

int main()
{
    int tag, radix;
    char s1[11], s2[11];
    long long n1, n2, t;

    scanf("%s %s %d %d", s1, s2, &tag, &radix);

    if (tag == 1)
    {
        n1 = base10(s1, radix);
    }
    else
    {
        n1 = base10(s2, radix);
        strcpy(s2, s1);
    }

    t = is_equal(s2, n1);

    if (t)
    {
        printf("%lld\n", t);
    }
    else
    {
        printf("Impossible\n");
    }

    return 0;
}