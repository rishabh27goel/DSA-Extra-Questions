#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// int longestSubarray(vector<int> &arr){

//     int n = arr.size();

//     int largest = 0;

//     for(int i=0; i<n; i++){

//         int sum = 0;

//         for(int j=i; j<n; j++){

//             sum += arr[j];

//             if(sum == 0){

//                 largest = max(j - i + 1, largest);
//             }
//         }
//     }

//     return largest;
// }

// Method 2 : Using Unordered Map
// Time Complexity : O(n)  Space Complexity : O(n)
int longestSubarray(vector<int> &arr){

    int n = arr.size();

    int largest = 0;
    int sum = 0;

    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){

        sum += arr[i];

        if(sum == 0){

            largest = i + 1;
        }
        else{

            if(mp.find(sum) == mp.end()){

                mp[sum] = i;
            }
            else{

                largest = max(i - mp[sum], largest);
            }
        }
    }

    return largest;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    // Input : 15 -2 2 -8 1 7 10 23
    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    int length = longestSubarray(arr);

    cout << "Length of Subarray : " << length;


    cout << endl;
    return 0;
}