#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool is_prime(int n, const vector<int> &primes)
{
    for (int p : primes)
    {
        if (p * p > n)
            break; // No need to check beyond the square root
        if (n % p == 0)
            return false;
    }
    return true;
}

// Function to find the nth prime number
int find_nth_prime(int n)
{
    vector<int> primes;
    int num = 2;

    // Keep finding primes until we reach the nth prime
    while (primes.size() < n)
    {
        if (is_prime(num, primes))
        {
            primes.push_back(num);
        }
        num++;
    }

    return primes.back(); // Return the nth prime number
}

int main()
{
    int n = 7;
    int nth_prime = find_nth_prime(n);
    cout << "The " << n << "th prime number is: " << nth_prime << endl;
    return 0;
}
