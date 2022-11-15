#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Method 1 : Sorting Array
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
// pair<int, int> findMinMax(vector<int> &arr){

//     int n = arr.size();

//     // Sort the array 
//     sort(arr.begin(), arr.end());


//     return make_pair(arr[0], arr[n-1]);
// }

// Method 2 : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
pair<int, int> findMinMax(vector<int> &arr){

    int n = arr.size();

    pair<int, int> minmax = make_pair(INT_MAX, INT_MIN);
 
    for(int i=0; i<n; i++){

        if(minmax.first > arr[i]){

            minmax.first = arr[i];
        }

        if(minmax.second < arr[i]){

            minmax.second = arr[i];
        }
    }

    return minmax;
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

    // Find the maximum and minimum element in an array
    pair<int, int> minmax = findMinMax(arr);

    cout << "Minimum Element : " << minmax.first << endl;
    cout << "Maximum Element : " << minmax.second;

    cout << endl;
    return 0;
}