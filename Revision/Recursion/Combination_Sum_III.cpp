#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void findCombi(int k, int start, int target, vector<int> &combi, vector<vector<int>> &result){
        // Base Case
        if(target == 0 && combi.size() == k){
            result.push_back(combi);
            return;
        }

        if(combi.size() == k || start >= 10) return;

        if(target - start >= 0){
            combi.push_back(start);
            findCombi(k, start + 1, target - start, combi, result);
            combi.pop_back();
        }

        findCombi(k, start + 1, target, combi, result);
    }


    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> result;
        vector<int> combi;

        findCombi(k, 1, target, combi, result);
        return result;
    }
};