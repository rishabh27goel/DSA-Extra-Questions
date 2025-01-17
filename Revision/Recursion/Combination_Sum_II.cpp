#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void findCombi(int n, vector<int> &candidates, int idx, int target, vector<int> &combi, vector<vector<int>> &result) {
        // Base Case
        if(target == 0){
            result.push_back(combi);
            return;
        }

        if(idx >= n)   return;

        if(target - candidates[idx] >= 0) {
            combi.push_back(candidates[idx]);
            findCombi(n, candidates, idx + 1, target - candidates[idx], combi, result);
            combi.pop_back();

            int next = idx;
            while(next < n && candidates[next] == candidates[idx]){
                next++;
            }

            findCombi(n, candidates, next, target, combi, result);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> combi;

        findCombi(n, candidates, 0, target, combi, result);
        return result;
    }
};