#include <iostream>
#include <cmath>

using namespace std;

long long largestPrimeFactor(long long n)
{
    long long maxPrime = -1;

    // Remove factors of 2
    while (n % 2 == 0)
    {
        maxPrime = 2;
        n /= 2;
    }

    // Check odd factors
    for (long long i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            maxPrime = i;
            n /= i;
        }
    }

    // If n is still greater than 2, it must be prime
    return (n > 2) ? n : maxPrime;
}

int main()
{
    long long num = 600851475143;
    cout << "Largest prime factor: " << largestPrimeFactor(num) << endl;
    return 0;
}
