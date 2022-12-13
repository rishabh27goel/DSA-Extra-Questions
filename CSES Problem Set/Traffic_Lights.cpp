#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

#define ll long long int

ll findElement(vector<ll> &length, ll target){

    ll i = 0;
    ll j = length.size()-1;

    while(i <= j){

        ll mid = i + (j - i) / 2;

        if(length[mid] == target){

            return mid;
        }
        else if(length[mid] > target){

            j = mid-1;
        }
        else{

            i = mid+1;
        }
    }

    return -1;
}

int main()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> length;

    length.push_back(0);
    length.push_back(n);


    for(ll i=0; i<q; i++){

        ll val;
        cin >> val;

        length.push_back(val);

        // Sort the vector
        sort(length.begin(), length.end());

        // Find the element
        ll maxLen = INT_MIN;
        ll j = 0;

        while(j < (ll) length.size()-1){

            maxLen = max(length[j+1] - length[j], maxLen);
            j++;
        }

        cout << maxLen << endl;
    }   



    cout << endl;
    return 0;
}