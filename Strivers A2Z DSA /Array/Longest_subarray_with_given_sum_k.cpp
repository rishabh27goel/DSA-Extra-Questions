#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O()  Space Complexity : O()
// int longestSubarray(vector<int> &arr, int k){

//     int n = arr.size();

//     int length = 0;

//     for(int i=0; i<n; i++){

//         int sum = 0;

//         for(int j=i; j<n; j++){

//             sum += arr[j];

//             if(sum == k){

//                 length = max(j-i+1, length);
//             }
//         }
//     }

//     return length;
// }

// Method 2 : Using Unordered Map
// Time Complexity : O(n)  Space Complexity : O(n)
int longestSubarray(vector<int> &arr, int k){

    int n = arr.size();

    int length = 0;

    unordered_map<int, int> mp;
    int sum = 0;

    for(int i=0; i<n; i++){

        sum += arr[i];

        // Check for previous elements in map if we have sum-k
        if(mp.find(sum-k) != mp.end())
            length = max(i-mp[sum-k], length);

        // Store sum if not present
        if(mp.find(sum) == mp.end())
            mp[sum] = i;

        
        if(sum == k)
            length = max(i+1, length);
    }

    return length;
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

    cout << "Enter k : ";
    int k;
    cin >> k;

    // Longest Subarray with given Sum K
    int length = longestSubarray(arr, k);

    cout << "Longest Subarray : " << length;


    cout << endl;
    return 0;
}