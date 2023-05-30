#include <iostream>
#include <vector>
using namespace std;

// Brute Force
// Time : O(n^2)  Space : O(1)
// int findMinimumOperation(vector<int> &arr, int k){

//     int n = arr.size();

//     int totalSum = 0;

//     for(int i=0; i<n; i++){

//         totalSum += arr[i];
//     }

//     int maxWindow = 0;
//     int target = totalSum - k;

//     for(int i=0; i<n; i++){

//         int sum = 0;

//         for(int j=i; j<n; j++){

//             sum += arr[j];

//             if(sum == target){

//                 maxWindow = max(j - i + 1, maxWindow);
//             }


//         }
//     }

//     return maxWindow == 0 ? -1 : n - maxWindow;
// } 

// Using Sliding Window
// Time : O(n)  Space : O(1)
int findMinimumOperation(vector<int> &arr, int k){

    int n = arr.size();

    int totalSum = 0;

    for(int i=0; i<n; i++){

        totalSum += arr[i];
    }

    if(totalSum == k)
        return n;
        

    int target = totalSum - k;
    totalSum = 0;

    int maxWindow = 0;
    int i = 0;
    int j = 0;

    while(j < n){

        totalSum += arr[j];

        while(i <= j && target <= totalSum){

            if(target == totalSum){

                maxWindow = max(j - i + 1, maxWindow);
            }

            totalSum -= arr[i];
            i++;
        }

        j++;
    }

    return maxWindow == 0 ? -1 : n - maxWindow;
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

    cout << "Enter target : ";
    int k;
    cin >> k;


    int minOperation = findMinimumOperation(arr, k);

    cout << "Minimum Operation : " << minOperation;


    cout << endl;
    return 0;
}