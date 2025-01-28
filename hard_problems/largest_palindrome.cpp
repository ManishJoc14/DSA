#include <iostream>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int num)
{
    int original = num, reversed = 0;
    while (num > 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

// Function to find the largest palindrome product
int largestPalindrome()
{
    int maxPalindrome = 0;

    for (int i = 999; i >= 100; i--)
    {
        for (int j = i; j >= 100; j--)
        {
            int product = i * j;
            if (isPalindrome(product) && product > maxPalindrome)
            {
                maxPalindrome = product;
            }
        }
    }
    return maxPalindrome;
}

int main()
{
    cout << "Largest Palindromic Product: " << largestPalindrome() << endl;
    return 0;
}
