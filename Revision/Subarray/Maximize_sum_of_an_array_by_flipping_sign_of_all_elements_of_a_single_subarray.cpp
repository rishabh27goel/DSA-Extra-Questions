#include <iostream>
#include <vector>
using namespace std;

// Brute Force
// Time : O(n^2)  Space : O(1)
// int maxSumOfArray(vector<int> &arr){

//     int n = arr.size();

//     int totalSum = 0;
//     int minSubarray = INT_MAX;

//     for(int i=0; i<n; i++){

//         int sum = 0;

//         for(int j=i; j<n; j++){

//             sum += arr[j];
//             minSubarray = min(sum, minSubarray);
//         }

//         totalSum += arr[i];
//     }


//     if(minSubarray > 0)
//         return totalSum;

//     return (totalSum - minSubarray) - minSubarray;
// }

// Kadane's Algorithm
// Time : O(n)  Space : O(1)
int maxSumOfArray(vector<int> &arr){

    int n = arr.size();

    int totalSum = 0;

    int minSubarray = INT_MAX;
    int sum = 0;

    for(int i=0; i<n; i++){

        sum += arr[i];
        minSubarray = min(minSubarray, sum);

        if(sum > 0)
            sum = 0;

        totalSum += arr[i];
    }


    if(minSubarray > 0)
        return totalSum;

    return (totalSum - minSubarray) - minSubarray;
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


    int maxSum = maxSumOfArray(arr);

    cout << "Maximum Sum : " << maxSum;


    cout << endl;
    return 0;
}