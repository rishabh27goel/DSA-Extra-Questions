#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        int first = -1;
        int second = -1;

        for(int i=0; i<n; i++){

            if(first < nums[i]-1){

                second = first;
                first = nums[i]-1;
            }
            else if(second < nums[i]-1){

                second = nums[i]-1;
            }
        }

        return first * second;
    }
};