#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findParent(int node, vector<int> &parent) {
        if(node == parent[node])
            return parent[node];

        return parent[node] = findParent(parent[node], parent);
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();
    
        vector<int> parent;
        vector<pair<int, int>> numIdx;       

        for(int j = 0; j < n; j++) {
            parent.push_back(j);
            numIdx.push_back(make_pair(nums[j], j));
        }

        // Sort the array with number and indexes
        sort(numIdx.begin(), numIdx.end(), [&](auto &one, auto &two) {
            return one.first < two.first;
        });

        for(int j = 1; j < n; j++) {
            int p1 = findParent(numIdx[j-1].second, parent);
            int p2 = findParent(numIdx[j].second, parent);

            if(abs(numIdx[j-1].first - numIdx[j].first) <= limit) {
                parent[p2] = p1;
            }
        }

        vector<vector<pair<int, int>>> parentMap(n);
        for(int j = 0; j < n; j++) {
            int p = findParent(numIdx[j].second, parent);
            parentMap[p].push_back(numIdx[j]);
        }

        for(auto &orgNum : parentMap) { 
            if(orgNum.size() == 0)
                continue;
            
            vector<int> sortedNum;
            for(int j = 0; j < orgNum.size(); j++) {
                sortedNum.push_back(orgNum[j].second);
            }

            sort(sortedNum.begin(), sortedNum.end(), [&](int &idx1, int &idx2) {
                return idx1 < idx2;
            });

            for(int j = 0; j < sortedNum.size(); j++) {
                nums[sortedNum[j]] = orgNum[j].first;
            }
        }

        return nums;
    }
};