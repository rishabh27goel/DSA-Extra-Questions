#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = prices.size();

        int minNum1 = INT_MAX;
        int minNum2 = INT_MAX;

        for(int i=0; i<n; i++){

            if(minNum1 > prices[i]){

                minNum2 = minNum1;
                minNum1 = prices[i];
            }
            else if(minNum2 > prices[i]){

                minNum2 = prices[i];
            }
        }

        return minNum1 + minNum2 > money ? money : money - (minNum1 + minNum2);
    }
};