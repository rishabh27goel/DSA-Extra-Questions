#include <iostream>
#include <vector>
using namespace std;

// Method : Sliding Window Approach & Dynamic Programming
// Time Complexity : O(n)  Space Complexity : O(n)
int overlappingSubarrays(vector<int> &arr, int target){

    int n = arr.size();

    vector<int> dp(n, INT_MAX);

    int result = INT_MAX;
    int best = INT_MAX;
    int sum = 0;

    int start = 0;
    int end = 0;

    while(end < n){

        sum += arr[end];

        while(sum > target){

            sum -= arr[start];
            start++;
        }

        if(sum == target){

            if(start-1 >= 0 && dp[start-1] != INT_MAX){

                result = min(result, dp[start-1] + (end - start + 1));
            }

            best = min(best, end - start + 1);
        }

        dp[end] = best;
        end++;
    }

    return result == INT_MAX ? -1 : result;
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

    cout << "Enter target : ";
    int target;
    cin >> target;

    // Two non-overlapping sub-arrays
    int length = overlappingSubarrays(arr, target);

    cout << "Minimum Length : " << length;


    cout << endl;
    return 0;
}