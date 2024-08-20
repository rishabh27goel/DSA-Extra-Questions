#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() 
{
    int n;
    cin >> n;

    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    ll totalMoves = 0;
    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1]){
            totalMoves += (arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
        }
    }

    cout << totalMoves;

    return 0;
}