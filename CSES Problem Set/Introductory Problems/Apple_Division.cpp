#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

#define ll long long

ll findMinDiff(int n, vector<int> &arr) {
    ll totalSum = 0;
    for(int j = 0; j < n; j++) {
        totalSum += arr[j];
    }

    ll power = pow(2, n);
    ll minDiff = LLONG_MAX;

    for(int j = 0; j < power; j++) {
        ll currSum = 0;
        for(int bit = 0; bit < n; bit++) {
            if(j & (1 << bit)) 
                currSum += arr[bit];
        }
        minDiff = min(minDiff, abs(totalSum - 2 * currSum));
    }
    return minDiff;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int j = 0; j < n; j++) {
        cin >> arr[j];
    }

    ll minDiff = findMinDiff(n, arr);
    cout << minDiff << endl;

    return 0;
}