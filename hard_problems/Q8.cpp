#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isokay(long long int num)
{

    vector<long long int> primeFactors;

    while (num % 2 == 0)
    {
        if (primeFactors.size() > 2)
        {
            return false;
        }
        primeFactors.push_back(2);
        num /= 2;
    }

    for (long long int i = 3; i * i < num; i += 2)
    {
        if (num % i == 0)
        {
            if (primeFactors.size() > 2)
            {
                return false;
            }
            primeFactors.push_back(i);
            num /= i;
        }
    }

    if (num > 2)
    {
        if (primeFactors.size() > 2)
        {
            return false;
        }
        primeFactors.push_back(num);
    }

    return true;
}

int main()
{
    long long int count = 0;
    vector<long long int> primeFactors;

    for (long long int i = 2; i < pow(10,8); i++)
    {
        if (isokay(i))
        {
            count++;
        }
    }
    cout << "The count is : " << count;

    return 0;
}