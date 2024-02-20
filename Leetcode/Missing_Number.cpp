#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findXor(int n){

        if(n % 4 == 0)
            return n;
        
        if(n % 4 == 3)
            return 0;

        if(n % 4 == 2)
            return n + 1;
        
        return 1;
    }

    int missingNumber(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int xorNum = findXor(n);
    
        for(int i=0; i<n; i++){
            xorNum ^= nums[i];
        }

        return xorNum;
    }
};