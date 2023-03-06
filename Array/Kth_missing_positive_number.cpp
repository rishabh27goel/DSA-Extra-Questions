#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Using Unordered Map
// Time Complexity : O(n + k)  Space Complexity : O(n)
// int missingNumber(vector<int> &arr, int k){

//     int n = arr.size();

//     unordered_map<int, int> mp;

//     for(int i=0; i<n; i++){

//         mp[arr[i]]++;
//     }

//     int c = 1;

//     while(k != 0){

//         if(mp.find(c) == mp.end()){

//             k--;

//             if(k == 0)
//                 return c;
//         }

//         c++;
//     }

//     return -1;
// }

// Method 2 : Without Map
// Time Complexity : O(n + k)  Space Complexity : O(1)
// int missingNumber(vector<int> &arr, int k){

//     int n = arr.size();

//     int c = 1;
//     int i = 0;

//     while(k != 0){

//         if(i < n){

//             if(arr[i] == c){

//                 i++;
//             }
//             else{

//                 k--;
//             }
//         }
//         else{

//             k--;
//         }

//         if(k == 0)
//             return c;

//         c++;
//     }

//     return -1;
// }

// Method 3 : Using Binary Search 
// Time Complexity : O(log(n))  Space Complexity : O(1)
int missingNumber(vector<int> &arr, int k){

    int n = arr.size();

    int i = 0;
    int j = n-1;

    while(i <= j){

        int mid = i + (j - i) / 2;
        int diff = arr[mid] - (mid + 1);

        if(diff < k){

            i = mid + 1;
        }
        else{

            j = mid - 1;
        }
    }

    return i + k;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    cout << "Enter k : ";
    int k;
    cin >> k;


    // Kth Missing Positive Number
    int number = missingNumber(arr, k);

    cout << "Missing Number : " << number;


    cout << endl;
    return 0;
}