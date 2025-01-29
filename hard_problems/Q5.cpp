#include <iostream>
#include <cmath>

using namespace std;

// #define number 600851475143
#define number 13195

long long int findLargestPrimeFactor(long long int num)
{
    long long int largetFactor = -1;

    while (num % 2 == 0)
    {
        largetFactor = 2;
        num /= 2;
    }

    for (long long int i = 3; i * i < num; i += 2)
    {
        if (num % i == 0)
        {
            largetFactor = i;
            num /= i;
        }
    }

    return num > 2 ? num : largetFactor;
}

int main()
{
    // prime factors of 13195 are 5, 7, 13, 29
    // largest factor is 29

    // similarly calculate for 600851475143
    // The largest prime factor is : 6857
    cout << "The largest prime factor is : " << findLargestPrimeFactor(number);

    return 0;
}