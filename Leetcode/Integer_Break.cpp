#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        
        ios_base::sync_with_stdio(false);

        if(n <= 3)
            return n-1;

        int powerVal = pow(3, (n/3) - 1);

        if(n % 3 == 0){

            return powerVal * 3;
        }
        else if(n % 3 == 1){

            return powerVal * 4;
        } 
        else{

            return powerVal * 6;
        }
    }
};