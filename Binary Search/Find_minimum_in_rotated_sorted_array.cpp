#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// Method 1 : Linear Method
// Time Complexity : O(n)   Space Complexity : O(1)
// int minimumInSortedArray(vector<int> &arr){

//     int n = arr.size();

//     // Find Minimum Element 
//     int minElement = INT_MAX;

//     for(int i=0; i<n; i++){

//         if(minElement > arr[i]){

//             minElement = arr[i];
//         }
//     }

//     return minElement;
// }

// Method 2 : Binary Search
// Time Complexity : O(log(n))   Space Complexity : O(1)
int minimumInSortedArray(vector<int> &arr){

    int n = arr.size();

    if(n == 1)
        return arr[0];

    // If array is not sorted
    if(arr[0] < arr[n-1])
        return arr[0];


    int i = 0;
    int j = n-1;

    while(i < j){

        int mid = i + (j - i) / 2;


        if(arr[mid] >= arr[0]){

            i = mid + 1;
        }
        else{

            j = mid;
        }
    }

    return arr[i];
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    cout << "Enter array : ";
    vector <int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }


    // Find Minimum in Rotated Sorted Array
    int minElement = minimumInSortedArray(arr);

    cout << "Minimum Element : " << minElement;


    cout << endl;
    return 0;
}