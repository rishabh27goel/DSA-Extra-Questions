#include <iostream>
#include <vector>
using namespace std;

#include <math.h>

// Method 1 : Brute Force
// Time Complexity : O(n * maxElement)  Space Complexity : O(1)
// int minimizeMaximum(vector<int> &arr){

//     int n = arr.size();

//     int finalMin = INT_MAX;
//     int maxNum = INT_MIN;

//     for(int i=0; i<n; i++){

//         maxNum = max(arr[i], maxNum);
//     }


//     int prevMax = maxNum;

//     // At max we can reduce element by maxElement 
//     while(true){

//         int maxEle = INT_MIN;

//         for(int i=0; i<n; i++){

//             maxEle = max(arr[i], maxEle);
//         }

//         if(prevMax < maxEle)
//             return prevMax;

//         if(maxEle == arr[0])
//             return maxEle;

//         finalMin = min(finalMin, maxEle);

//         for(int i=1; i<n; i++){

//             if(arr[i] == maxEle){

//                 arr[i-1]++;
//                 arr[i]--;
//             }
//         }

//         prevMax = maxEle;
//     }

//     return finalMin;
// }

// Method 2 : Using Binary Search
// Time Complexity : O(n * log(maxElement))  Space Complexity : O(1)
// bool check(vector<int> &arr, int maxPossible){

//     int n = arr.size();

//     // If maxElement is smaller than arr[0] then it is not a possible candidate
//     if(arr[0] > maxPossible)
//         return false;

//     long prev = arr[0];

//     for(int i=1; i<n; i++){

//         long diff = maxPossible - prev;

//         prev = arr[i] - diff;

//         if(prev > maxPossible)
//             return false;
//     }

//     return true;
// }

// int minimizeMaximum(vector<int> &arr){

//     int n = arr.size();

//     int maxNum = INT_MIN;

//     for(int i=0; i<n; i++){

//         maxNum = max(arr[i], maxNum);
//     }

//     int result = -1;
//     int start = 0;
//     int end = maxNum;

//     while(start <= end){

//         int mid = start + (end - start) / 2;

//         if(check(arr, mid) == true){

//             result = mid;
//             end = mid - 1;
//         }
//         else{

//             start = mid + 1;
//         }
//     }

//     return result;
// }

// Method 3 : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
int minimizeMaximum(vector<int> &arr){

    int n = arr.size();

    long result = INT_MIN;
    long prefix = 0;

    for(int i=0; i<n; i++){

        prefix += arr[i];

        long value = ceil((double) prefix / ((double) i + 1.0));
        result = max(result, value);
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

    // Minimize Maximum of Array
    int minMax = minimizeMaximum(arr);

    cout << "Maximum is : " << minMax;


    cout << endl;
    return 0;
}