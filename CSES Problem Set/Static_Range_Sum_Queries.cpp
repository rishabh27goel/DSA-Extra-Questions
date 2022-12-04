#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

int main()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);

    vector<ll> prefix(n);
    long sum = 0;

    for(ll i=0; i<n; i++){

        cin >> arr[i];
    
        sum += arr[i];
        prefix[i] = sum;
    }

    for(ll j=0; j<q; j++){

        ll a, b;
        cin >> a >> b;

        ll result;

        if(a - 2 >= 0)
            result = prefix[b-1] - prefix[a - 2];
        else    
            result = prefix[b-1];

        cout << result << endl;
    }

    cout << endl;
    return 0;
}