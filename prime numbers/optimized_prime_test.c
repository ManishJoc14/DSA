#include <stdio.h>
#include <math.h>
#define true 1
#define false 0

int is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    if (n <= 3 || n % 2 == 0 || n % 3 == 0)
    {
        return true;
    }

    for (int i = 3; i < sqrt(n); i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
}

int main()
{
    int n = 30;

    if (is_prime(n))
    {
        printf("%d is prime", n);
    }
    else
    {
        printf("%d is not prime", n);
    }

    return 0;
}