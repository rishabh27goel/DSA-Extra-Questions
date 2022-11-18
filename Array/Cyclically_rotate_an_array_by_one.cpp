#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Reverse Helper
// Time Complexity : O(n)   Space Complexity : O(1)
// void reverseArr(vector<int> &arr, int i, int j){

//     while(i <= j){

//         swap(arr[i], arr[j]);
//         i++;
//         j--;
//     }
// }

// void rotateByOne(vector<int> &arr){

//     int n = arr.size();

//     // Reverse full array
//     reverseArr(arr, 0, n-1);

//     // Reverse from index 1
//     reverseArr(arr, 1, n-1);
// }

// Method 2 : Linear Method
// Time Complexity : O(n)   Space Complexity : O(1)
void rotateByOne(vector<int> &arr){

    int n = arr.size();

    int last = arr[n-1];
    int i = n-2;

    while(i >= 0){

        arr[i+1] = arr[i];
        i--;
    }

    arr[0] = last;
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

    // Cyclically rotate an array by one
    rotateByOne(arr);

    cout << "Updated Array : ";

    for(int i=0; i<arr.size(); i++){

        cout << arr[i] << " ";
    }


    cout << endl;
    return 0;
}