#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = colors.size();

        int total = 0;
        int i = 0;

        while(i < n) {

            int sum = 0;
            int maxNum = INT_MIN;

            int c = 0;
            char ch = colors[i];

            while(i < n && ch == colors[i]) {

                maxNum = max(neededTime[i], maxNum);
                sum += neededTime[i];
                c++;
                i++;
            }

            if(c > 1)
                total += (sum - maxNum);
        }

        return total;
    }
};