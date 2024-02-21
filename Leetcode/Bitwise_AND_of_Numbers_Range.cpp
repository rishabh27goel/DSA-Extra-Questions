#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
 
    int rangeBitwiseAnd(int left, int right) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        while(right > left){

            right = (right & (right-1));
        }

        return right;
    }
};