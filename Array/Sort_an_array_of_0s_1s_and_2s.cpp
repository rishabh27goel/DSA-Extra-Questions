#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method 1 : Sorting
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
// vector<int> sortArrayOf012(vector<int> &arr){

//     // Using sort function
//     sort(arr.begin(), arr.end());


//     return arr;
// }

// Method 2 : Counting 0s, 1s, 2s
// Time Complexity : O(n)  Space Complexity : O(1)
// void addValue(vector<int> &arr, int &ind, int value, int count){

//     while(count--){

//         arr[ind] = value;
//         ind++;
//     }
// }

// vector<int> sortArrayOf012(vector<int> &arr){

//     int zero = 0;
//     int one = 0;
//     int two = 0;

//     for(int i=0; i<arr.size(); i++){

//         if(arr[i] == 0){

//             zero++;
//         }
//         else if(arr[i] == 1){

//             one++;
//         }
//         else{

//             two++;
//         }
//     }

//     int i = 0;

//     addValue(arr, i, 0, zero);
//     addValue(arr, i, 1, one);
//     addValue(arr, i, 2, two);

//     return arr;
// }

// Method 3 : Three Pointer Method
// Time Complexity : O(n)  Space Complexity : O(1)
vector<int> sortArrayOf012(vector<int> arr){

    int n = arr.size();

    int i = 0;
    int j = 0;
    int k = n-1;

    while(j <= k){

        if(arr[j] == 0){

            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if(arr[j] == 1){

            j++;
        }
        else{

            swap(arr[j], arr[k]);
            k--;
        }
    }

    return arr;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> arr(size);
    cout << "Enter array : ";

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    // Sort an array of 0s, 1s and 2s
    vector<int> nums = sortArrayOf012(arr);

    cout << "Sorted Array : ";

    for(int i=0; i<nums.size(); i++){

        cout << nums[i] << " ";
    }


    cout << endl;
    return 0;
}