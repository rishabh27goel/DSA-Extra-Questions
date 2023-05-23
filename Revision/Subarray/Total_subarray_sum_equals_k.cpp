#include <iostream>
#include <unordered_map>
using namespace std;

// Brute Force
// Time : O(n^2)   Space : O(1)
// int totalSubarray(vector<int> &nums, int target){

//     int n = nums.size();

//     int total = 0;

//     for(int i=0; i<n; i++){

//         int prefix = 0;

//         for(int j=i; j<n; j++){

//             prefix += nums[i];

//             if(prefix == target)
//                 total++;
//         }
//     }

//     return total;
// }

// Using Map
// Time : O(n)   Space : O(n)
int totalSubarray(vector<int> &nums, int target){

    int n = nums.size();

    int total = 0;
    int prefix = 0;

    unordered_map<int, int> mp;
    mp[0] = 1;

    for(int i=0; i<n; i++){

        prefix += nums[i];
        
        total += mp[prefix-target];
    
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


    cout << "Enter target : ";
    int target;
    cin >> target;


    int total = totalSubarray(arr, target);

    cout << "Total Subarrays : " << total;


    cout << endl;
    return 0;
}