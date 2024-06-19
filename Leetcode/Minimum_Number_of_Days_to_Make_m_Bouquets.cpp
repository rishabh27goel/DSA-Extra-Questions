#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkMinDays(int n, vector<int> &bloomDay, int days, int m, int k){
        
        int j = 0;
    
        while(j < n){
            if(bloomDay[j] > days){
                j++;
            }
            else {
                int c = 0;
                while(j < n && bloomDay[j] <= days){
                    c++;
                    j++;
                }

                m -= (c / k);
                if(m <= 0)
                    return true;
            }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = bloomDay.size();

        // int maxRange = *max_element(bloomDay.begin(), bloomDay.end());
        
        int result = -1;
        int start = 1;
        int end = 1e9;

        while(start <= end){
            int days = start + (end - start) / 2;
            if(checkMinDays(n, bloomDay, days, m, k)){
                result = days;
                end = days - 1;
            }
            else {
                start = days + 1;
            }
        }

        return result;
    }
};