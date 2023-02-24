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

    // As we want to check previous element of mid
    while(i < j){

        int mid = i + (j - i) / 2;

        // Check previous element
        if(arr[mid] == arr[mid-1]){

            // If mid is odd
            if(mid % 2 == 1){

                // Search right half
                i = mid+1;
            }
            else{

                // Search left half
                j = mid;
            }
        }
        else{

            // If mid is odd
            if(mid % 2 == 1){

                // Search right half
                j = mid-1;
            }
            else{

                // Search left half
                i = mid;
            }
        }
    }

    return arr[i];
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