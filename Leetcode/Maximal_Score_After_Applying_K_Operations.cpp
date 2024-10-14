#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        priority_queue <double> pq;
        for(int j = 0; j < n; j++)
            pq.push((double) nums[j]);
    
        long long score = 0;
        while(k--) {
            double top = pq.top();
            pq.pop();

            score += top;
            pq.push((int) ceil(top / 3));
        }

        return score;
    }
};