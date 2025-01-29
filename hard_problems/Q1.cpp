#include <iostream>
#include <cmath>

using namespace std;

int findProductOfRequiuredTriplet(int sum)
{

    for (int a = 0; a < 1000 / 3; ++a)
    {
        for (int b = a; b < 1000 / 2; ++b)
        {
            int c = sum - a - b;

            if (c * c == a * a + b * b)
            {
                cout << "a = " << a << "b = " << b << "c = " << c;
                return a * b * c;
            }
        }
    }
}

int main()
{
    // find triplet for which
    // a + b + c = 1000;
    // a*b*c = ????

    cout << "The product of required triplet is: " << findProductOfRequiuredTriplet(1000);

    // a = 200
    // b = 375
    // c = 425
    // The product of required triplet is: 31875000

    return 0;
}