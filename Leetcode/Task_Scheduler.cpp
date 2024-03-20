#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int m = tasks.size();

        int total = 0;
        
        unordered_map<char, int> mp;
        int maxCount = 0;

        for(int i=0; i<m; i++){

            maxCount = max(maxCount, ++mp[tasks[i]]);
        }

        total += ((n + 1) * (maxCount-1));

        for(auto child : mp){
            if(child.second == maxCount)
                total++;
        }

        return max(m, total);
    }
};