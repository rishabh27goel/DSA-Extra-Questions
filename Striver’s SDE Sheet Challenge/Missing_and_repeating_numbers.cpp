#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Using Map
// Time : O(n)  Space : O(n)
// pair<int, int> missingAndRepeating(vector<int> &arr, int n){

//     int repeated;
//     int missing;

//     unordered_map<int, int> mp;

//     for(int i=0; i<n; i++){

//         if(mp.find(arr[i]) != mp.end())
//             repeated = arr[i];

//         mp[arr[i]]++;
//     }

//     for(int i=1; i<=n; i++){

//         if(mp.find(i) == mp.end()){

//             missing = i;
//             break;
//         } 
//     }

//     return make_pair(missing, repeated);
// }

// Space Optimisation
// Time : O(n)  Space : O(1)
pair<int, int> missingAndRepeating(vector<int> &arr, int n){

    int repeated;
    int missing;

    int xorArr = 0;

    for(int i=0; i<n; i++){

        xorArr ^= arr[i];
    }

    for(int i=1; i<=n; i++){

        xorArr ^= i;
    }

    // Get the leftmost set bit
    int leftMostBit = xorArr & ~(xorArr-1);

    int x = 0;
    int y = 0;

    for(int i=0; i<n; i++){

        if(arr[i] & leftMostBit)
            x ^= arr[i];
        else
            y ^= arr[i];
    }

    for(int i=1; i<=n; i++){

        if(i & leftMostBit)
            x ^= i;
        else
            y ^= i;
    }

    return make_pair(x, y);
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }


    pair<int, int> pr = missingAndRepeating(arr, n);

    cout << "Missing & Repeated Number : " << pr.first << " " << pr.second;


    cout << endl;
    return 0;
}