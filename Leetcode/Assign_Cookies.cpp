#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int total = 0;
        int i = 0;
        int j = 0;

        while(i < n && j < m){

            while(j < m && g[i] > s[j]){

                j++;
            }

            if(i < n && j < m && g[i] <= s[j]){

                total++;
                j++;
            }
        
            i++;
        }

        return total;
    }
};