#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute Force
// Time : O(n^2)  Space : O(1)
// int smallestSubarray(vector<int> &arr, int p){

//     int n = arr.size();

//     long totalSum = 0;

//     for(int i=0; i<n; i++)
//         totalSum += arr[i];


//     // If no removal is required
//     if(totalSum % p == 0)
//         return 0;


//     int result = INT_MAX;

//     for(int i=0; i<n; i++){

//         long subarraySum = 0;

//         for(int j=i; j<n; j++){

//             subarraySum += arr[j];

//             if(totalSum != subarraySum && (totalSum - subarraySum) % p == 0){

//                 result = min(result, j - i + 1);
//             }
//         }
//     }

//     return (result == INT_MAX ? -1 : result);
// }


// Using Map
// Logic : Subarray of target sum & Subarray divisible by p
// Time : O(n)  Space : O(n)
int smallestSubarray(vector<int> &arr, int p){

    int n = arr.size();

    long totalSum = 0;

    for(int i=0; i<n; i++)
        totalSum += arr[i];


    // If no removal is required
    if(totalSum % p == 0)
        return 0;


    int result = INT_MAX;
    unordered_map<int, int> mp;

    long sum = 0;
    int target = totalSum % p;    

    for(int i=0; i<n; i++){

        sum = (sum + arr[i]) % p;
        
        // If current matches with target
        if(sum == target)
            result = min(result, i + 1);

        // If the value has reached less than 0 [ -2 -> -2 + p ]
        int pos = sum - target;

        if(pos < 0)
            pos += p;


        if(mp.find(pos) != mp.end())
            result = min(result, i - mp[pos]);


        mp[sum] = i;
    }

    return ((result == INT_MAX || result == n) ? -1 : result);
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
    
    cout << "Enter p : ";
    int p;
    cin >> p;


    int smallest = smallestSubarray(arr, p);

    cout << "Smallest Subarray to be removed : " << smallest;


    cout << endl;
    return 0;
}