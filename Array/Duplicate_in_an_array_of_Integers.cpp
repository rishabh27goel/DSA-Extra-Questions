#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// int duplicateIntegers(vector<int> &arr){

//     int n = arr.size();

//     for(int i=0; i<n; i++){

//         for(int j=i+1; j<n; j++){

//             if(arr[i] == arr[j])
//                 return arr[i];
//         }
//     }

//     return -1;
// }

// Method 2 : Sorting the array
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
// int duplicateIntegers(vector<int> &arr){

//     int n = arr.size();

//     // Sort the array
//     sort(arr.begin(), arr.end());

//     int i = 0;

//     while(i < n-1){

//         if(arr[i] == arr[i+1])
//             return arr[i]; 

//         i++;
//     }

//     return -1;
// }

// Method 3 : Using Unordered Map
// Time Complexity : O(n)  Space Complexity : O(n)
int duplicateIntegers(vector<int> &arr){

    int n = arr.size();

    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){

        if(mp.find(arr[i]) != mp.end())
            return arr[i];

        mp[arr[i]] = i;
    }

    return -1;
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

    // Duplicate in an array of Integers
    int duplicate = duplicateIntegers(arr);

    cout << "Duplicate Integers : " << duplicate;


    cout << endl;
    return 0;
}