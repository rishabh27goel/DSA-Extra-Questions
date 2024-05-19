#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        long long total = 0;
        int minNum = INT_MAX;
        long long c = 0;

        for(auto num : nums){
            // If node is increased
            if((num ^ k) > num){
                total += (num ^ k);
                minNum = min(minNum, (num^k) - num);
                c++;
            }
            else{
                total += num;
                minNum = min(minNum, num - (num^k));
            }
        }

        if(c % 2 == 0)
            return total;

        return total - minNum;
    }
};