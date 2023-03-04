#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// int countSubarray(vector<int> &arr, int minX, int maxX){

//     int n = arr.size();

//     int result = 0;

//     for(int i=0; i<n; i++){

//         int minVal = INT_MAX;
//         int maxVal = INT_MIN;

//         for(int j=i; j<n; j++){

//             minVal = min(arr[j], minVal);
//             maxVal = max(arr[j], maxVal);

//             if(minVal == minX && maxVal == maxX)
//                 result++;
//         }
//     }

//     return result;
// }

// Method 2 : Linear Method [ keeping track of previous valid window ]
// Time Complexity : O(n)  Space Complexity : O(1)
int countSubarray(vector<int> &arr, int minX, int maxX){

    int n = arr.size();

    int result = 0;
    int lowerBound = -1;
    int i = 0;

    int prevMin = -1;
    int prevMax = -1;

    for(int i=0; i<n; i++){

        if(arr[i] >= minX && arr[i] <= maxX){

            prevMin = (arr[i] == minX) ? i : prevMin;
            prevMax = (arr[i] == maxX) ? i : prevMax;
        
            result += max(0, min(prevMin, prevMax) - lowerBound);
        }
        else{

            prevMin = -1;
            prevMax = -1;
            lowerBound = i;
        }
    }

    return result;
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

    cout << "Enter Min Value : ";
    int minX;
    cin >> minX;

    cout << "Enter Max Value : ";
    int maxX;
    cin >> maxX;

    
    int count = countSubarray(arr, minX, maxX);

    cout << "Count is : " << count;


    cout << endl;
    return 0;
}