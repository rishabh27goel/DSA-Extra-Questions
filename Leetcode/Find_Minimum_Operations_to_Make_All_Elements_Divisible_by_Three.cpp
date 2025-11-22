#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int size = nums.size();

        int operations = 0;
        for(int num : nums) {
            int rem = num % 3;
            operations += (rem == 0 ? 0 : 1);
        }
        return operations;
    }
};