#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
// int singleElement(vector<int> &arr){

//     int n = arr.size();

//     int element = 0;

//     for(int i=0; i<n; i++){

//         element ^= arr[i];
//     }

//     return element;
// }

// Method 2 : Binary Search
// Time Complexity : O(log(n))  Space Complexity : O(1)
int singleElement(vector<int> &arr){

    int n = arr.size();

    int i = 0;
    int j = n-1;

    return 0;
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

    int element = singleElement(arr);

    cout << "Single Element : " << element;


    cout << endl;
    return 0;
}