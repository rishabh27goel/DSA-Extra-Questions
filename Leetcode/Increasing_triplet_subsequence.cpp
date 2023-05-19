#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time : O(n^3)   Space : O(1)
// bool increasingTriplet(vector<int> &arr){

//     int n = arr.size();

//     for(int i=0; i<n; i++){

//         for(int j=i+1; j<n; j++){

//             for(int k=j+1; k<n; k++){

//                 if(arr[i] < arr[j] && arr[j] < arr[k])
//                     return true;
//             }
//         }
//     }

//     return false;
// }

// Method 2 : Optimised Time
// Time : O(n^2)   Space : O(1)
// bool increasingTriplet(vector<int> &arr){

//     int n = arr.size();

//     for(int i=0; i<n; i++){

//         int middle = INT_MAX;

//         for(int j=i+1; j<n; j++){

//             if(arr[j] > arr[i] && arr[j] < middle){

//                 middle = arr[j];
//             }
//             else if(middle != INT_MAX && middle < arr[j]){

//                 return true;
//             }
//         }
//     }

//     return false;
// }

// Method 3 : Optimised Time
// Time : O(n)   Space : O(1)
bool increasingTriplet(vector<int> &arr){

    int n = arr.size();

    int first = INT_MAX;
    int middle = INT_MAX;

    for(int j=0; j<n; j++){

        if(arr[j] < first){

            first = arr[j];
        }
        else if(arr[j] > first && arr[j] < middle){

            middle = arr[j];
        }
        else if(middle != INT_MAX && middle < arr[j]){

            return true;
        }
    }

    return false;
}


int main()
{
    cout << "Enter array size : ";
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }


    bool exist = increasingTriplet(arr);

    cout << (exist ? "Exist" : "Not Exist");


    cout << endl;
    return 0;
}