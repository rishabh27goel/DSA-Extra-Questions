#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int mod = 1e9 + 7;

    int n;
    cin >> n;

    long val = 1;

    while(n--){

        val = (val * 2) % mod;
    }

    cout << val;


    return 0;
}