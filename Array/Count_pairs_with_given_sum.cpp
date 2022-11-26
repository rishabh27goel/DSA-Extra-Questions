#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// int countPairs(vector<int> &arr, int k){

//     int n = arr.size();

//     int count = 0;

//     for(int i=0; i<n; i++){

//         for(int j=i+1; j<n; j++){

//             if(arr[i] + arr[j] == k){

//                 count++;
//             }
//         }
//     }

//     return count;
// }

// Method 2 : Linear Method
// Time Complexity : O(n)  Space Complexity : O(n)
int countPairs(vector<int> &arr, int k){

    int n = arr.size();

    int count = 0;
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){

        if(mp.find(k - arr[i]) != mp.end()){

            count += mp[k - arr[i]];
        }

        mp[arr[i]]++;
    }

    return count;
}

int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;

    cout << "Enter array : ";
    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    cout << "Enter target : ";
    int target;
    cin >> target;


    // Count pairs with given sum
    int count = countPairs(arr, target);

    cout << "Pairs Count : " << count;


    cout << endl;
    return 0;
}