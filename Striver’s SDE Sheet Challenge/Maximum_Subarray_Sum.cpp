#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

// Brute Force
// Time : O(n^2)  Space : O(1)
// ll maxSubarraySum(vector<int> &arr, int n)
// {
//     ll maxSum = 0;

//     for(int i=0; i<n; i++){

//         ll currSum = 0;

//         for(int j=i; j<n; j++){

//             currSum += arr[j];

//             maxSum = max(currSum, maxSum);
//         }
//     }

//     return maxSum;
// }


// Kadane's Algorithm
// Time : O(n)  Space : O(1)
ll maxSubarraySum(vector<int> &arr, int n)
{
    ll maxSum = 0;
    ll currSum = 0;

    for(int i=0; i<n; i++){

        currSum += arr[i];

        maxSum = max(currSum, maxSum);
    
        if(currSum < 0)
            currSum = 0;
    }

    return maxSum;
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


    ll maxSum = maxSubarraySum(arr, n);

    cout << "Maximum Sum : " << maxSum;


    cout << endl;
    return 0;
}