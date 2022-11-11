#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long n;
    cin >> n;

    long total = 0;

    while(n != 0){

        total += (n / 5);

        n /= 5;
    }

    cout << total;

    return 0;
}