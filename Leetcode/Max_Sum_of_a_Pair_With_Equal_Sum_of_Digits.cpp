#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getDigitSum(int num) {
        int digitSum = 0;
        while(num > 0) {
            digitSum += (num % 10);
            num /= 10;
        }
        return digitSum;
    }

    // Time : O(n ^ 2)  Space : O(1)
    // int maximumSum(vector<int>& nums) {
    //     int n = nums.size();

    //     int maxSum = -1;
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < n; j++) {
    //             if(i != j) {
    //                 int sumOne = getDigitSum(nums[i]);
    //                 int sumTwo = getDigitSum(nums[j]);

    //                 if(sumOne == sumTwo)
    //                     maxSum = max(maxSum, nums[i] + nums[j]);
    //             }
    //         }
    //     }
    //     return maxSum;
    // }

    /*
        18 43 36 13 7   171
        9  7  9  4  7   9

    */

    // int maximumSum(vector<int>& nums) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = nums.size();

    //     unordered_map<int, int> greatestNumberMap;
    //     int maxSum = -1;

    //     for(int i = 0; i < n; i++) {
    //         int digitSum = getDigitSum(nums[i]);
    //         if(greatestNumberMap.find(digitSum) == greatestNumberMap.end()) {
    //             greatestNumberMap[digitSum] = nums[i];
    //         }
    //         else {
    //             maxSum = max(maxSum, greatestNumberMap[digitSum] + nums[i]);
    //             greatestNumberMap[digitSum] = max(nums[i], greatestNumberMap[digitSum]);
    //         }
    //     }

    //     return maxSum;
    // }

    int maximumSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        vector<int> greatestNumberMap(100, -1);
        int maxSum = -1;

        for(int i = 0; i < n; i++) {
            int digitSum = getDigitSum(nums[i]);
            if(greatestNumberMap[digitSum] == -1) {
                greatestNumberMap[digitSum] = nums[i];
            }
            else {
                maxSum = max(maxSum, greatestNumberMap[digitSum] + nums[i]);
                greatestNumberMap[digitSum] = max(nums[i], greatestNumberMap[digitSum]);
            }
        }

        return maxSum;
    }

    // int maximumSum(vector<int>& nums) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     sort(nums.begin(), nums.end(), [&](const int &x, const int &y) {
    //         int sumOne = getDigitSum(x);
    //         int sumTwo = getDigitSum(y);

    //         return sumOne < sumTwo;
    //     });

    //     int maxSum = -1;
    //     int numIdx = 0;

    //     while(numIdx < n) {
    //         int digitSum = getDigitSum(nums[numIdx]);
    //         int largest = -1;
    //         int secondLargest = -1;

    //         while(numIdx < n && digitSum == getDigitSum(nums[numIdx])) {
    //             if(largest < nums[numIdx]) {
    //                 secondLargest = largest;
    //                 largest = nums[numIdx];
    //             }
    //             else if(secondLargest < nums[numIdx]) {
    //                 secondLargest = nums[numIdx];
    //             }
    //             numIdx++;
    //         }

    //         if(largest != -1 && secondLargest != -1)
    //             maxSum = max(largest + secondLargest, maxSum);
    //     }

    //     return maxSum;
    // }
};