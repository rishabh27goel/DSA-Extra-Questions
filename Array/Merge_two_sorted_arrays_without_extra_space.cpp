#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n1 * n2)  Space Complexity : O(1)
// void mergeTwoSortedArrays(vector<int> &arr1, vector<int> &arr2){

//     int n1 = arr1.size();
//     int n2 = arr2.size();

//     int j = n2-1;

//     while(j >= 0){

//         int i = n1-1;
//         int last = arr1[i];

//         while(i >= 0 && arr1[i] > arr2[j]){

//             if(i + 1 < n1){

//                 arr1[i+1] = arr1[i];
//             }
            
//             i--;
//         }

//         // We can not change when i is still at n-1
//         if(i != n1 - 1){

//             arr1[++i] = arr2[j];
//             arr2[j] = last;
//         }

//         j--;
//     }
// }

// Method 2 : 3-Pointer Approach
// Time Complexity : O((n1 + n2) + (n1 * log(n1) + (n2 * log(n2))))  Space Complexity : O(1)
void mergeTwoSortedArrays(vector<int> &arr1, vector<int> &arr2){

    int n1 = arr1.size();
    int n2 = arr2.size();

    int i = 0;
    int k = n1-1;

    int j = 0;

    while(i <= k && j < n2){

        if(arr1[i] < arr2[j]){

            i++;
        }
        else{

            swap(arr1[k], arr2[j]);
            
            k--;
            j++;
        }
    }

    // Now we have all the elements but not sorted
    // So we will sort the resulted arrays
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int main()
{
    cout << "Enter size : ";
    int size1, size2;
    cin >> size1 >> size2;

    cout << "Enter array 1 : ";
    vector<int> arr1(size1);

    for(int i=0; i<size1; i++){

        cin >> arr1[i];
    }

    cout << "Enter array 2 : ";
    vector<int> arr2(size2);

    for(int i=0; i<size2; i++){

        cin >> arr2[i];
    }

    // Merge two sorted arrays with O(1) extra space
    mergeTwoSortedArrays(arr1, arr2);

    cout << "Merged Sorted Array : ";

    for(int i=0; i<size1; i++){

        cout << arr1[i] << " ";
    }

    for(int i=0; i<size2; i++){

        cout << arr2[i] << " ";
    }


    cout << endl;
    return 0;
}