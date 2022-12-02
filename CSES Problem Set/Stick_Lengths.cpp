#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll diff = 0;

    for(int i=0; i<n; i++){

        diff += abs(arr[i] - arr[n/2]);
    }

    cout << diff;

    return 0;
}