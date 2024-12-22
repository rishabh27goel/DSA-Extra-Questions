#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// class Solution {
// public:
//     vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
//         int n = heights.size();
//         int q = queries.size();

//         vector<int> queryResult(q, -1);
//         vector<vector<pair<int, int>>> queryMap(n);
    
//         for(int j = 0; j < q; j++) {
//             int x = queries[j][0];
//             int y = queries[j][1];

//             if(x == y) {
//                 queryResult[j] = x;
//             }
//             else if(x > y && heights[x] > heights[y]) {
//                 queryResult[j] = x;
//             }
//             else if(x < y && heights[x] < heights[y]) {
//                 queryResult[j] = y;
//             }
//             else {
//                 int end = max(x, y);
//                 queryMap[end].push_back({max(heights[x], heights[y]), j});
//             }
//         }
    
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
//         for(int j = 0; j < n; j++) {
//             while(!minHeap.empty() && minHeap.top().first < heights[j]) {
//                 queryResult[minHeap.top().second] = j;
//                 minHeap.pop();
//             }

//             for(auto &qry : queryMap[j]) {
//                 minHeap.push(qry);
//             }
//         }

//         return queryResult;
//     }
// };

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int q = queries.size();

        vector<int> queryResult(q, -1);
        vector<pair<int, int>> queryIdx;

        for(int j = 0; j < q; j++) {
            int x = queries[j][0];
            int y = queries[j][1];

            if(x == y) {
                queryResult[j] = x;
            }
            else if(x > y && heights[x] > heights[y]) {
                queryResult[j] = x;
            }
            else if(x < y && heights[x] < heights[y]) {
                queryResult[j] = y;
            }
            else {
                queryIdx.push_back({max(queries[j][0], queries[j][1]), j});
            }
        }

        sort(queryIdx.begin(), queryIdx.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int start = 0;

        for(int j = 0; j < n; j++) {
            while(start < queryIdx.size() && queryIdx[start].first <=  j) {
                int idx = queryIdx[start].second;
                minHeap.push({max(heights[queries[idx][0]], heights[queries[idx][1]]), start});
                start++;
            }    

            while(!minHeap.empty() && minHeap.top().first < heights[j]) {
                int idx = minHeap.top().second;
                queryResult[queryIdx[idx].second] = j;
                minHeap.pop();
            }   
        }

        return queryResult;
    }
};