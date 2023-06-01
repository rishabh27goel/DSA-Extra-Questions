#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute Force
// Time : O(n^2)  Space : O(1)
// int findSubarraysWithXor(vector<int> &arr, int target){

//     int n = arr.size();

//     int total = 0;

//     for(int i=0; i<n; i++){

//         int xorNum = 0;

//         for(int j=i; j<n; j++){

//             xorNum ^= arr[j];

//             if(target == xorNum)
//                 total++;
//         }
//     }

//     return total;
// } 

// Using Map
// Time : O(n)  Space : O(n)
int findSubarraysWithXor(vector<int> &arr, int target){

    int n = arr.size();

    int total = 0;

    unordered_map<int, int> mp;
    mp[0] = 1;

    int xorNum = 0;

    for(int i=0; i<n; i++){

        xorNum ^= arr[i];

        total += mp[xorNum ^ target];
        mp[xorNum]++;
    }

    return total;
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

    cout << "Enter target : ";
    int target;
    cin >> target;


    int totalSubarrays = findSubarraysWithXor(arr, target);

    cout << "Total Subarray : " << totalSubarrays;


    cout << endl;
    return 0;
}