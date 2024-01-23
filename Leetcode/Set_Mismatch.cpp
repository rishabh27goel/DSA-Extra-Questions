#include <iostream>
using namespace std;

class Solution {
public:

    int findXor(int n){

        if(n % 4 == 0)
            return n;

        else if(n % 4 == 1)
            return 1;
        
        else if(n % 4 == 2)
            return n+1;

        return 0;
    }

    vector<int> findErrorNums(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);

        int n = nums.size();

        int rangeXor = findXor(n);
        int xorNum = 0;

        for(int i=0; i<n; i++){

            xorNum ^= nums[i];
        }

        int combinedXor = (rangeXor ^ xorNum);
        int setBit = (combinedXor & ~(combinedXor-1));
        
        int group1 = 0;
        int group2 = 0;

        for(int i=0; i<n; i++){
            if(setBit & nums[i]){
                group1 ^= nums[i];
            }
            else {
                group2 ^= nums[i];
            }
        }

        for(int i=1; i<=n; i++){
            if(setBit & i){
                group1 ^= i;
            }
            else {
                group2 ^= i;
            }
        }

        int c = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == group1)
                c++;
        }

        if(c == 2)
            return {group1, group2};

        return {group2, group1};
    }
};