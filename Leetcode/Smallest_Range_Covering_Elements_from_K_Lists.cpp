#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// class Solution {
// public:
//     class Info {
//         public:
//             int value;
//             int row;
//             int col;

//         Info(int row, int col, int value) {
//             this->row = row;
//             this->col = col;
//             this->value = value;
//         }
//     };

//     class Compare {
//         public:
//             bool operator()(Info* f1, Info* f2) {
//                 return f1->value > f2->value;
//             }
//     };

//     vector<int> smallestRange(vector<vector<int>>& nums) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);

//         int n = nums.size();

//         priority_queue<Info*, vector<Info*>, Compare> minHeap;
//         int minRange = INT_MAX;
//         int endPoint = -1;

//         int maxNum = INT_MIN;
//         int minNum = INT_MAX;

//         for(int j = 0; j < n; j++) {
//             minHeap.push(new Info(j, 0, nums[j][0]));
//             minNum = min(minNum, nums[j][0]);
//             maxNum = max(maxNum, nums[j][0]);
//         }

//         while(!minHeap.empty()) {
//             Info* top = minHeap.top();
//             minHeap.pop();

//             int row = top->row;
//             int col = top->col;
//             int smallest = top->value;

//             if(minRange > maxNum - smallest) {
//                 minRange = maxNum - smallest;
//                 endPoint = maxNum;
//             }

//             if(col + 1 < nums[row].size()) {
//                 int curr = nums[row][col + 1];
//                 maxNum = max(maxNum, curr);
//                 minHeap.push(new Info(row, col+1, curr));
//             }
//             // As we want atleast one item from each list
//             else 
//                 break;
//         }

//         return {endPoint - minRange, endPoint};
//     }
// };

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        vector<pair<int, int>> mergedValues;
        for(int i = 0; i < n; i++) {
            for(auto child : nums[i]) {
                mergedValues.push_back(make_pair(child, i));
            }
        }

        sort(mergedValues.begin(), mergedValues.end());

        int m = mergedValues.size();
        
        vector<int> freqCount(n, 0);
        int elements = 0;

        int start = 0;
        int end = 0;

        int rangeStart = 0;
        int rangeEnd = INT_MAX;

        while(end < m) {
            auto smallest = mergedValues[end];
            if(++freqCount[smallest.second] == 1)   
                elements++;

            while(start <= end && elements == n) {
                int currRange = mergedValues[end].first - mergedValues[start].first;
                if(currRange < rangeEnd - rangeStart) {
                    rangeStart = mergedValues[start].first;
                    rangeEnd = mergedValues[end].first;
                }

                if(--freqCount[mergedValues[start].second] == 0)   
                    elements--;

                start++;
            }

            end++;
        }

        return {rangeStart, rangeEnd};
    }
};