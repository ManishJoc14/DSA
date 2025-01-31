// Problem:
// Find the positive integer x starting from 1234
// such that reversing its digits gives a number that is a multiple of x

// Example:
// If x = 12
// then reversing it gives 21, which is not a multiple of 12. However, for some number
// x, this condition holds true.

#include <iostream>
#include <algorithm>

using namespace std;

// Function to reverse the digits of a number
long long int reverseNumber(long long int num)
{
    long long int reversed = 0;
    while (num > 0)
    {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

// Function to find the smallest number that satisfies the condition
long long int findSmallestNumber()
{
    long long int x = 1234;
    while (true)
    {
        long long int reversedX = reverseNumber(x);
        if (reversedX % x == 0) // is reverse of x exactly divisible by x
        {
            return x;
        }
        x++;
    }
}

int main()
{
    cout << "The smallest number is: " << findSmallestNumber() << endl;
    return 0;
}
