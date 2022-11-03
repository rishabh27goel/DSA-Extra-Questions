#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
// int peakIndex(vector<int> &arr){

//     int n = arr.size();

//     for(int i=0; i<n-1; i++){

//         if(arr[i] > arr[i+1])
//             return i;
//     }

//     return -1;
// }

// Method 2 : Binary Search
// Time Complexity : O(log(n))  Space Complexity : O(1)
int peakIndex(vector<int> &arr){

    int n = arr.size();

    // Find the Peak Index    
    int i = 0;
    int j = n-1;

    while(i < j){

        int mid = i + (j - i) / 2;

        if(arr[mid] < arr[mid+1]){

            i = mid + 1;
        }
        else{

            j = mid;  
        }
    }

    return i;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    cout << "Enter array : ";
    vector<int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }


    // Peak Index in a Mountain Array
    int peak = peakIndex(arr);

    cout << "Peak Index : " << peak;


    cout << endl;
    return 0;
}