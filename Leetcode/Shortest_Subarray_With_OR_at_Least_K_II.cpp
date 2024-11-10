#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void handleNumber(int *bitsCount, int number, int type) {
        int j = 0;
        while(number > 0) {
            if(number & 1)
                bitsCount[j] += type;
        
            number >>= 1;
            j++;
        }
    }

    int windowOr(int *bitsCount) {
        int number = 0;
        int mask = 1;

        for(int i = 0; i < 32; i++) {
            if(bitsCount[i] > 0)
                number |= mask;
            
            mask <<= 1;
        }

        return number;
    }

    int minimumSubarrayLength(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int bitsCount[32] = {0};
        int minSubarray = INT_MAX;

        int i = 0;
        int j = 0;

        while(j < n) {
            handleNumber(bitsCount, nums[j], 1);
            
            while(i <= j && windowOr(bitsCount) >= k) {
                minSubarray = min(minSubarray, j - i + 1);
                handleNumber(bitsCount, nums[i], -1);
                i++;
            }

            j++;
        }

        return minSubarray == INT_MAX ? -1 : minSubarray;
    }
};