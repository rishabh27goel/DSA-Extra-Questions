#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force [Two Loops]
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// int largestSum(vector<int> &arr){

//     int n = arr.size();

//     int maxSum = INT_MIN;

//     for(int i=0; i<n; i++){

//         int sum = 0;

//         for(int j=i; j<n; j++){

//             sum += arr[j];

//             maxSum = max(sum, maxSum);
//         }
//     }

//     return maxSum;
// }

// Method 2 : Divide and Conquer
// Time Complexity : O(n * log(n))  Space Complexity : O(log(n) or Stack Space)
int findingSum(vector<int> &arr, int l, int m, int r){

    // Finding Left Half Sum
    int leftMax = INT_MIN; 
    int leftSum = 0;

    for(int i=l; i<=m; i++){

        leftSum += arr[i];

        if(leftSum > leftMax)
            leftMax = leftSum;

        if(leftSum < 0)
            leftSum = 0;
    }

    // Finding Right Half Sum
    int rightMax = INT_MIN;
    int rightSum = 0;

    for(int i=m; i<=r; i++){

        rightSum += arr[i];

        if(rightSum > rightMax)
            rightMax = rightSum;

        if(rightSum < 0)
            rightSum = 0;
    }

    // Return max from [left], [right], and [left to right]
    return max(max(leftSum, rightSum), leftSum + rightSum - arr[m]);
}

int divideAndConquer(vector<int> &arr, int l, int r){

    // Base Case
    if(l > r)
        return INT_MIN;

    // Only single element
    if(l == r)
        return arr[l];


    // Find middle point
    int m = (l + r) / 2;


    // We will use logic like Merge Sort
    // Case 1 : Left Subarray [For Divide]
    // Case 2 : Right Subarray [For Divide]
    // Case 3 : Finding sum using helper function [For Conquer]

    return max(max(divideAndConquer(arr, l, m-1), divideAndConquer(arr, m+1, r)), findingSum(arr, l, m, r));
}

int largestSum(vector<int> &arr){

    int n = arr.size();

    return divideAndConquer(arr, 0, n-1);
}

// Method 3 : Kadane's Algorithm
// Time Complexity : O(n)  Space Complexity : O(1)
// int largestSum(vector<int> &arr){

//     int n = arr.size();

//     int maxSum = INT_MIN;
//     int currSum = 0;

//     for(int i=0; i<n; i++){

//         currSum += arr[i];

//         if(currSum > maxSum)
//             maxSum = currSum;

//         if(currSum < 0)
//             currSum = 0;
//     }

//     return maxSum;
// }

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

    // Largest Sum Contiguous Subarray
    int sum = largestSum(arr);

    cout << "Largest Sum : " << sum;

    cout << endl;
    return 0;
}