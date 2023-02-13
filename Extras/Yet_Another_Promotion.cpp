#include <iostream>
using namespace std;

#define ll long long int

int main()
{
    ll t;
    cin >> t;

    while(t--){

        ll a, b;
        cin >> a >> b;  

        ll n, m;
        cin >> n >> m;

        ll result = 0;

        if((b * (m + 1)) < (a * m)){

            result = b * n;
        }        
        else{

            ll mul = n / (m + 1);
            ll div = n % (m + 1);

            result = mul * a * m;

            if(div != 0){

                result += (div * min(a, b));
            }
        }

        if(n == 1)
            result = min(a, b);

        cout << result << endl;
    }

    return 0;
}