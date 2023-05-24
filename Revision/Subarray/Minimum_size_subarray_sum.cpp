#include <iostream>
#include <vector>
using namespace std;

// Brute Force
// Time : O(n^2)  Space : O(1)
// int minSizeSubarray(vector<int> &arr, int target){

//     int n = arr.size();

//     int result = INT_MAX;

//     for(int i=0; i<n; i++){

//         int prefix = 0;

//         for(int j=i; j<n; j++){

//             prefix += arr[j];

//             if(prefix >= target){

//                 result = min(result, j - i + 1);
//                 break;
//             }
//         }
//     }

//     return result == INT_MAX ? 0 : result;
// }

// Sliding Window
// Time : O(n)  Space : O(1)
int minSizeSubarray(vector<int> &arr, int target){

    int n = arr.size();

    int result = INT_MAX;
    int prefix = 0;

    int i = 0;
    int j = 0;

    while(j < n){

        prefix += arr[j];

        while(i <= j && prefix >= target){

            result = min(result, j - i + 1);
            prefix -= arr[i];
            i++;
        }

        j++;
    }

    return result == INT_MAX ? 0 : result;
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


    int size = minSizeSubarray(arr, target);

    cout << "Minimum Size Subarray : " << size;


    cout << endl;
    return 0;
}