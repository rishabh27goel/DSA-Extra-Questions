#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &str){
        int i = 0;
        int j = str.size()-1;

        while(i <= j){
            if(str[i] != str[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    void findPartition(int n, string &str, int idx, vector<string> &partition, vector<vector<string>> &result) {
        if(idx >= n){
            result.push_back(partition);
            return;
        }

        string sub = "";
        for(int j = idx; j < n; j++){
            sub.push_back(str[j]);

            if(isPalindrome(sub)){
                partition.push_back(sub);
                findPartition(n, str, j + 1, partition, result);
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string str) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = str.size();

        vector<vector<string>> result;
        vector<string> partition;
        
        findPartition(n, str, 0, partition, result);
        return result;
    }

    // vector<vector<string>> result;
    // vector<vector<bool>> isPalin;

    // void findPartition(int n, string &str, int idx, vector<string> &partition) {
    //     if(idx >= n){
    //         result.push_back(partition);
    //         return;
    //     }

    //     string sub = "";
    //     for(int j = idx; j < n; j++){
    //         sub.push_back(str[j]);
            
    //         if(isPalin[idx][j]){
    //             partition.push_back(sub);
    //             findPartition(n, str, j + 1, partition);
    //             partition.pop_back();
    //         }
    //     }
    // }

    // vector<vector<string>> partition(string str) {
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = str.size();

    //     isPalin.resize(n, vector<bool> (n, false));
    //     for(int k = 0; k < str.size(); k++){
    //         int i = k;
    //         int j = k;

    //         while(i >= 0 && j < n && str[i] == str[j]){
    //             isPalin[i][j] = true;
    //             i--, j++;
    //         }

    //         i = k;
    //         j = k + 1;

    //         while(i >= 0 && j < n && str[i] == str[j]){
    //             isPalin[i][j] = true;
    //             i--, j++;
    //         }
    //     }

    //     vector<string> partition;
    //     findPartition(n, str, 0, partition);
    //     return result;
    // }
};