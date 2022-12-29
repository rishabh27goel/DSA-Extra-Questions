#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Extra Space
// Time Complexity : O(n)  Space Complexity : O(n)
// vector<int> rotateKPlaces(vector<int> &arr, int k){

//     int n = arr.size();

//     k = k % n;

//     vector<int> rotated(n);

//     for(int i=0; i<n-k; i++){

//         rotated[i + k] = arr[i];
//     }

//     for(int i=n-k; i<n; i++){

//         rotated[i-n+k] = arr[i];
//     }

//     return rotated;
// }

// Method 2 : Optimised Space Method
// Time Complexity : O(n)  Space Complexity : O(k)
// vector<int> rotateKPlaces(vector<int> &arr, int k){

//     int n = arr.size();

//     k = k % n;

//     if(k == 0)  
//         return arr;

//     vector<int> rotated(k);

//     for(int i=n-k; i<n; i++){

//         rotated[i-n+k] = arr[i];
//     }

//     for(int i=n-k-1; i>=0; i--){

//         arr[i+k] = arr[i];
//     }

//     for(int i=0; i<k; i++){

//         arr[i] = rotated[i];
//     }

//     return arr;
// }

// Method 3 : No extra space
// Time Complexity : O(n)  Space Complexity : O(1)
void reverseArray(vector<int> &arr, int start, int end){

    if(start >= end)
        return;

    while(start < end){

        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

vector<int> rotateKPlaces(vector<int> &arr, int k){

    int n = arr.size();

    k = k % n;

    if(k == 0)  
        return arr;

    // Reverse the full array
    reverseArray(arr, 0, n-1);

    // Parts to reverse
    reverseArray(arr, 0, k-1);
    reverseArray(arr, k, n-1);

    return arr;
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

    cout << "Enter k : ";
    int k;
    cin >> k;


    // Rotate by k places
    vector<int> nums = rotateKPlaces(arr, k);

    cout << "Updated Array : ";

    for(int i=0; i<n; i++){

        cout << nums[i] << " ";
    }


    cout << endl;
    return 0;
}