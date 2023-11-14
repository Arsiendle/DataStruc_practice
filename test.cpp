#include <stdio.h>
#include <math.h>
// prime(p)判断p是否为 素数
int prime(int p)
{
    if (p < 2)
    {
        return 0;
    }
    // 1到p之间的数,不包含1和p
    for (int i = 2; i <= sqrt(p); i++)
    {
        if (p % i == 0)
        {
            // 能够整除,即不是素数,返回0
            return 0;
        }
    }
    // 循环结束,没有找到能够整除的数,即素数,返回1
    return 1;
}

int prime_sum(int m, int n)
{
    int sum = 0;
    for (int p = m; p <= n; p++)
    {
        sum = sum + (prime(p) ? p : 0);
    }
    return sum;
}

int main()
{
    int m, n, p;
    scanf("%d %d", &m, &n);
    printf("sum of(%d,%d)=%d", m, n, prime_sum(m, n));
    return 0;
}