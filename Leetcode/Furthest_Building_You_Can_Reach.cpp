#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        long totalDiff = 0;
        long ladderSum = 0;
        int reach = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=1; i<n; i++){

            if(nums[i] > nums[i-1]){

                int diff = nums[i] - nums[i-1];
                totalDiff += diff;

                pq.push(diff);
                ladderSum += diff;

                if(pq.size() > ladders){
                    ladderSum -= pq.top();
                    pq.pop();
                }

                long bricksLeft = totalDiff - ladderSum;
                if(bricksLeft > bricks)
                    break;
            }

            reach = i;
        }

        return reach;
    }
};