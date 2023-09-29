#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     bool isMonotonic(vector<int>& nums) {
        
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);

//         int n = nums.size();

//         int c1 = 1;
//         int i = 1;

//         while(i < n){

//             if(nums[i] >= nums[i-1])
//                 c1++;

//             i++;
//         }

//         int c2 = 1;
//         i = 1;

//         while(i < n){

//             if(nums[i] <= nums[i-1])
//                 c2++;

//             i++;
//         }

//         return (c1 == n || c2 == n);
//     }
// };

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        if(n <= 2)
            return true;


        int i = 0;
        
        while(i + 1 < n && nums[i] == nums[i+1]){

            i++;
        }

        if(i + 1 >= n)
            return true;


        bool type = (nums[i+1] - nums[i] > 0 ? true : false);
        
        for(i=i+2; i<n; i++){

            if(type){

                if(nums[i] < nums[i-1])
                    return false;
            }
            else {

                if(nums[i] > nums[i-1])
                    return false;
            }
        }

        return true;
    }
};