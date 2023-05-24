#include <iostream>
#include <vector> 
using namespace std;

// Brute Force
// Time : O(n^2)  Space : O(1)  
// int maxSubarraySum(vector<int> &arr){

//     int n = arr.size();

//     int result = INT_MIN;

//     for(int i=0; i<n; i++){

//         int sum = 0;

//         for(int j=i; j<n; j++){

//             sum += arr[j];
//             result = max(result, sum);
//         }
//     }

//     return result;
// }

// Kadane's Algorithm
// Time : O(n)  Space : O(1)  
int maxSubarraySum(vector<int> &arr){

    int n = arr.size();

    int result = INT_MIN;
    int sum = 0;

    for(int i=0; i<n; i++){

        sum += arr[i];
        result = max(result, sum);

        if(sum < 0)
            sum = 0;
    }

    return result;
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

    
    int maxSum = maxSubarraySum(arr);

    cout << "Maximum Subarray Sum : " << maxSum;



    cout << endl;
    return 0;
}