#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int m = roads.size();

        vector<int> degree(n, 0);
        for(int i=0; i<m; i++){
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }

        vector<int> freq(n, 0);
        for(int i=0; i<n; i++){
            freq[degree[i]]++;
        }

        long long result = 0;
        long long time = 1;
        for(int i=0; i<n; i++){
            if(freq[i] == 0)
                continue;

            int c = freq[i];
            while(c--){
                result += (i * time);
                time++;
            }            
        }

        return result;
    }
};