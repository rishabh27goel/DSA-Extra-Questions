#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

// int main()
// {
//     int n;
//     cin >> n;

//     long result = 1;
//     for(int j = 1; j <= n; j++) {
//         result = ((result % mod) * 2) % mod ;
//     }

//     cout << result << " ";

//     return 0;
// }

int main()
{
    int n;
    cin >> n;

    long result = 1;
    long mul = 2;  

    while(n > 0) {
        if(n & 1)
            result = ((result % mod) * (mul % mod)) % mod;

        mul = (mul % mod * mul % mod) % mod;
        n >>= 1;
    }

    cout << result << " ";
    return 0;
}