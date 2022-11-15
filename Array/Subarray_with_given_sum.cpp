#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n ^ 2)   Space Complexity : O(1)
// pair<int, int> subarraySum(vector<int> &arr, int target){

//     int n = arr.size();

//     for(int i=0; i<n; i++){

//         int currSum = 0;

//         for(int j=i; j<n; j++){

//             currSum += arr[j];

//             if(currSum == target){

//                 return make_pair(i, j);
//             }
//         }
//     }

//     return make_pair(-1, -1);
// }

// Method 2 : Sliding Window Approach
// Time Complexity : O(n)   Space Complexity : O(1)
pair<int, int> subarraySum(vector<int> &arr, int target){

    int n = arr.size();

    int currSum = 0;
    int start = 0;
    int end = 0;

    while(end < n){

        while(end < n && currSum + arr[end] <= target){

            currSum += arr[end];

            if(currSum == target)
                return make_pair(start, end);

            end++;
        }

        currSum -= arr[start];
        start++;
    }

    return make_pair(-1, -1);
}

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

    cout << "Enter target : ";
    int target;
    cin >> target;


    // Subarray with given sum
    pair<int, int> sumInd = subarraySum(arr, target);

    cout << "Sub-Array is : ";

    for(int i=sumInd.first; i<=sumInd.second; i++){

        cout << arr[i] << " ";
    }


    cout << endl;
    return 0;
}