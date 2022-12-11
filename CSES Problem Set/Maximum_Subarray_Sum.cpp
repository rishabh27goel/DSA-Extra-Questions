#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define ll long long int

int main()
{
    ll n;
    cin >> n;

    vector<ll> arr(n);

    ll maxSum = INT_MIN;
    ll currSum = 0;

    for(ll i=0; i<n; i++){

        cin >> arr[i];
    
        currSum += arr[i];

        maxSum = max(currSum, maxSum);
    
        if(currSum < 0)
            currSum = 0;
    }


    cout << maxSum;


    cout << endl;
    return 0;
}