#include <iostream>
using namespace std;

// Function to compute GCD (Greatest Common Divisor)
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// Function to compute LCM (Least Common Multiple)
long long lcm(int a, int b)
{
    return (long long)a * (b / gcd(a, b));
}

// Function to find LCM of numbers 1 to 20
long long smallestMultiple()
{
    long long result = 1;
    for (int i = 2; i <= 20; i++)
    {
        result = lcm(result, i);
    }
    return result;
}

int main()
{
    cout << "Smallest Multiple: " << smallestMultiple() << endl;
    return 0;
}
