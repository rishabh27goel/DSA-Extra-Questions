#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = items.size();
        int q = queries.size();

        vector<int> idx;
        for(int i = 0; i < q; i++) 
            idx.push_back(i);

        // Sort both the array
        sort(items.begin(), items.end());
        sort(idx.begin(), idx.end(), [&](int &idx1, int &idx2){
            return queries[idx1] < queries[idx2]; 
        });

        int maxNum = 0;
        int i = 0;

        vector<int> answer(q);
        for(int j = 0; j < q; j++) {
            while(i < n && items[i][0] <= queries[idx[j]]) {
                maxNum = max(maxNum, items[i][1]);
                i++;
            }

            answer[idx[j]] = maxNum;
        }

        return answer;
    }

    // vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = items.size();
    //     int q = queries.size();

    //     // Sort both the array
    //     sort(items.begin(), items.end());
        
    //     int maxRank = 0;
    //     for(int j = 0; j < n; j++) {
    //         maxRank = max(items[j][1], maxRank);
    //         items[j][1] = maxRank;
    //     }

    //     vector<int> answer;
    //     for(int j = 0; j < q; j++) {
            
    //         int idx = -1;
    //         int start = 0;
    //         int end = n-1;

    //         while(start <= end) {
    //             int mid = start + (end - start) / 2;
    //             if(items[mid][0] <= queries[j]) {
    //                 idx = mid;
    //                 start = mid + 1;
    //             }
    //             else {
    //                 end = mid - 1;
    //             }
    //         }

    //         answer.push_back(idx == -1 ? 0 : items[idx][1]);
    //     }

    //     return answer;
    // }
};