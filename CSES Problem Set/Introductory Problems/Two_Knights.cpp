#include <iostream>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;

    for(ll k = 1; k <= n; k++) {
        ll totalWays = ((k * k) * ((k * k) - 1)) / 2;
        ll attackWays = 4 * (k - 1) * (k - 2);

        cout << totalWays - attackWays << endl;
    }

    return 0;
}