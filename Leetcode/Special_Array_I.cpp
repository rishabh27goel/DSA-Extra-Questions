#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        int parity = (nums[0] % 2);
        int j = 1;

        while(j < n && !parity == (nums[j] % 2)) {
            j++;
            parity = !parity;
        }

        return j == n;
    }
};