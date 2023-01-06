#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Sorting the array
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
// int appearOnce(vector<int> &arr){

//     int n = arr.size();

//     if(n == 1)
//         return arr[0];

//     // Sort the array
//     sort(arr.begin(), arr.end());


//     if(arr[0] != arr[1])
//         return arr[0];


//     for(int i=1; i<n-1; i++){

//         if(arr[i-1] != arr[i] && arr[i] != arr[i+1])
//             return arr[i];
//     }

//     return arr[n-1];
// }

// Method 2 : Using Unordered Map
// Time Complexity : O(n)  Space Complexity : O(n)
// int appearOnce(vector<int> &arr){

//     int n = arr.size();

//     if(n == 1)
//         return arr[0];

//     unordered_map<int, int> mp;

//     for(int i=0; i<n; i++){

//         mp[arr[i]]++;
//     }

//     ffor(int i=0; i<n; i++){

//         if(mp[arr[i]] == 1)
//             return arr[i];
//     }

//     return -1;
// }

// Method 3 : Using Xor
// Time Complexity : O(n)  Space Complexity : O(1)
int appearOnce(vector<int> &arr){

    int n = arr.size();

    if(n == 1)
        return arr[0];

    int totalXor = 0;

    for(int i=0; i<n; i++){

        totalXor ^= arr[i];
    }

    return totalXor;
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

    // Element appear once
    int element = appearOnce(arr);

    cout << "Element is : " << element;


    cout << endl;
    return 0;
}