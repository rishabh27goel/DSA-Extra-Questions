#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // void findCombi(int n, int k, int start, vector<int> &sub, vector<vector<int>> &result){
    //     if(sub.size() == k){
    //         result.push_back(sub);
    //         return;
    //     }
        
    //     int size = sub.size();
    //     for(int j = start; j + (k - size) - 1 <= n; j++){
    //         sub.push_back(j);
    //         findCombi(n, k, j + 1, sub, result);
    //         sub.pop_back();
    //     }
    // }

    vector<vector<int>> combine(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<int>> result;
        vector<int> sub;
        findCombi(n, k, 1, sub, result);
        return result;
    }

    void findCombi(int n, int k, int start, vector<int> &sub, vector<vector<int>> &result){
        if(sub.size() == k){
            result.push_back(sub);
            return;
        }
        
        int size = sub.size();
        for(int j = start; j + (k - size) - 1 <= n; j++){
            sub.push_back(j);
            findCombi(n, k, j + 1, sub, result);
            sub.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<int>> result;
        vector<int> sub;
        findCombi(n, k, 1, sub, result);
        return result;
    }
};