#include <iostream>
using namespace std;

// Method : Using bit of power
// Time Complexity : O(log(n))  Space Complexity : O(1)
double power(double x, int n){

    // Base Case
    if(n == 0)
        return 1;

    if(n == 1)
        return x;

    double result = 1;
    double mul = x;
    int p = n;

    if(n < 0)
        p = -p;

    while(p > 0){

        if(p & 1)
            result *= mul;

        mul *= mul;
        p >>= 1;
    }

    if(n < 0)
        return (1.0 / result);

    return result;
}

int main()
{
    cout << "Enter value : ";
    double x;
    cin >> x;

    cout << "Enter power : ";
    int n;
    cin >> n;

    double result = power(x, n);

    cout << "Result is : " << result;


    cout << endl;
    return 0;
}