#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int lengthOf(long long int num)
{
    int length = 0;
    while (num != 0)
    {
        num /= 10;
        length++;
    }
    return length;
}

vector<int> getDigits(long long int number)
{
    vector<int> digits;
    while (number != 0)
    {
        digits.push_back(number % 10);
        number /= 10;
    }
    return digits;
}

vector<int> sortDigits(vector<int> digits)
{
    sort(digits.begin(), digits.end());
    return digits;
}

bool areDigitsSame(long long int x, long long int product)
{
    vector<int> digitsOfX = getDigits(x);
    vector<int> digitsOfProduct = getDigits(product);

    digitsOfX = sortDigits(digitsOfX);
    digitsOfProduct = sortDigits(digitsOfProduct);

    if (digitsOfX.size() != digitsOfProduct.size())
    {
        return false;
    }

    for (int i = 0; i < digitsOfX.size(); i++)
    {
        if (digitsOfX[i] != digitsOfProduct[i])
        {
            return false;
        }
    }

    return true;
}

bool isSame(long long int x)
{
    vector<long long int> products = {2 * x, 3 * x, 4 * x, 5 * x};

    for (int product : products)
    {
        if (lengthOf(x) != lengthOf(product))
        {
            return false;
        }

        if (!areDigitsSame(x, product))
        {
            return false;
        }
    }

    return true;
}

long long int findNumber()
{
    long long int x = 1;
    while (!isSame(x))
    {
        x++;
    }
    return x;
}

int main()
{

    // 142857 * 1 = 142857
    // 142857 * 2 = 285714
    // 142857 * 3 = 428571
    // 142857 * 4 = 571428
    // 142857 * 5 = 714285

    // 142857 is the smallest number having same digits but place interchanged upto 5x

    cout << "The smallest number is : " << findNumber() << endl;
    return 0;
}
