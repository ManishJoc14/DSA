// Each new term in the Fibonacci sequence is generated by adding the previous two terms.
// By starting with 1 and 2, the first 10 terms will be:
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, . . .
// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

#include <iostream>

using namespace std;

#define size 100

int main()
{
    long int temp = 0;
    long int sum = 0;
    long int arr[size];

    arr[0] = 1;
    arr[1] = 2;

    cout << "The require series is : " << arr[0] << " " << arr[1] << " ";
    for (int i = 2; i < size; i++)
    {
        temp = arr[i - 2] + arr[i - 1];
        if (temp >= 4000000)
            break;

        if (temp % 2 == 0)
        {
            sum += temp;
        }
        arr[i] = temp;
        cout << arr[i] << " ";
    }

    cout << endl
         << "The sum of the even number in the series is " << sum << endl;
    return 0;
}