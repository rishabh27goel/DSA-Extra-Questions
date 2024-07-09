#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = customers.size();

        double totalWaiting = 0;
        double maxReach = 0;

        for(int i=0; i<n; i++){
            if(customers[i][0] < maxReach){
                double extraWait = maxReach - customers[i][0];
                totalWaiting += extraWait;
                totalWaiting += customers[i][1];
                maxReach += customers[i][1];
            }
            else {  
                totalWaiting += customers[i][1];
                maxReach = (customers[i][0] + customers[i][1]); 
            }
        }

        return totalWaiting / n;
    }
};