#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Brute Force
// Time : O(n^2)  Space : O(1)
// int totalSubarray(vector<int> &nums, int k){

//     int n = nums.size();

//     int total = 0;

//     for(int i=0; i<n; i++){

//         int prefix = 0;

//         for(int j=i; j<n; j++){

//             prefix += nums[j];

//             if(prefix % k == 0)
//                 total++;
//         }
//     }

//     return total;
// }

// Using Map
// Time : O(n)  Space : O(n)
int totalSubarray(vector<int> &nums, int k){

    int n = nums.size();

    int total = 0;

    unordered_map<int, int> mp;
    mp[0] = 1;

    int prefix = 0;

    for(int i=0; i<n; i++){

        prefix = (prefix + nums[i]) % k;

        if(prefix < 0)
            prefix += k;

        total += mp[prefix];
        mp[prefix]++;
    }

    return total;
}

int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    cout << "Enter k : ";
    int k;
    cin >> k;


    int total = totalSubarray(arr, k);

    cout << "Total Subarrays : " << total;


    cout << endl;
    return 0;
}