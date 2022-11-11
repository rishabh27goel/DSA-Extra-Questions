#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Using Extra Space
// Time Complexity : O(n)  Space Complexity : O(n)
// vector<int> reverseArray(vector<int> &arr){

//     int n = arr.size();

//     vector<int> rev;

//     for(int i=n-1; i>=0; i--){

//         rev.push_back(arr[i]);
//     }

//     return rev;
// }

// Method 2 : Recursion Method
// Time Complexity : O(n)  Space Complexity : O(n)
// void reverseArr(vector<int> &arr, int i, int j){

//     // Base Case
//     if(i >= j)
//         return;

//     swap(arr[i], arr[j]);

//     reverseArr(arr, i+1, j-1);    
// }

// vector<int> reverseArray(vector<int> &arr){

//     int n = arr.size();

//     int i = 0;
//     int j = n-1;

//     reverseArr(arr, i, j);

//     return arr;
// }

// Method 3 : No extra space [Two Pointer]
// Time Complexity : O(n)  Space Complexity : O(1)
vector<int> reverseArray(vector<int> &arr){

    int n = arr.size();

    int i = 0;
    int j = n-1;

    while(i < j){

        swap(arr[i], arr[j]);

        i++;
        j--;
    }

    return arr;
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

    // Reverse the array
    vector<int> rev = reverseArray(arr);

    cout << "Reverse Array : ";

    for(int i=0; i<rev.size(); i++){

        cout << rev[i] << " ";
    }


    cout << endl;
    return 0;
}