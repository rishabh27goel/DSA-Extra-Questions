#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        ios_base::sync_with_stdio(false);

        int result = 0;
        int leftOver = 0;

        while(numBottles > 0){
            result += numBottles;

            int totalEmpty = leftOver + numBottles;

            leftOver = totalEmpty % numExchange;
            numBottles = (totalEmpty / numExchange);
        }

        return result;
    }
};