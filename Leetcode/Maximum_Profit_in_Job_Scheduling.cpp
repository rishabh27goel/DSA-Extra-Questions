#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    class JobObject {

        public:
            int startTime;
            int endTime;
            int profit;

        JobObject(int startTime, int endTime, int profit){

            this->startTime = startTime;
            this->endTime = endTime;
            this->profit = profit;
        }
    };

    int findLowerBound(int n, vector<JobObject*> &job, int target){

        int idx = -1;
        int i = 0;
        int j = job.size()-1;

        while(i <= j){

            int mid = i + (j - i) / 2;

            if(job[mid]->startTime >= target){
                idx = mid;
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }

        return idx;
    }


    int dp[50001];

    int findMaxProfit(int n, vector<JobObject*> &job, int idx){

        // Base Case
        if(idx >= n)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        
        int exclude = findMaxProfit(n, job, idx+1);

        // If we include current idx

        // Method 1: Will give TLE
        // int j = idx + 1;

        // while(j < n && job[idx]->endTime > job[j]->startTime){

        //     j++;
        // }

        // Method 2 : Binary Search
        int index = findLowerBound(n, job, job[idx]->endTime);

        int include = job[idx]->profit + findMaxProfit(n, job, index == -1 ? n : index);

        return dp[idx] = max(include, exclude);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = startTime.size();

        // Create a combination vector
        vector<JobObject*> job;

        for(int i=0; i<n; i++){

            job.push_back(new JobObject(startTime[i], endTime[i], profit[i]));
        }

        // Sort by startTime
        sort(job.begin(), job.end(), [&](JobObject* j1, JobObject* j2){

            return j1->startTime < j2->startTime;
        });

        memset(dp, -1, sizeof(dp));

        return findMaxProfit(n, job, 0);
    }
};