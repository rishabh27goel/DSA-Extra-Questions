#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> degree(n, 0);

        for(auto &itr : edges) {
            degree[itr[1]]++;
        }

        int champion = -1;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 0) {
                if(champion != -1)
                    return -1;

                champion = i;
            }
        }

        return champion;
    }
};