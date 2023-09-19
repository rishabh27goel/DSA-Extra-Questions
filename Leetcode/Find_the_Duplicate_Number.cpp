#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     bool visited[n+1];

    //     memset(visited, false, sizeof(visited));
    
    //     for(int i=0; i<n; i++){

    //         if(visited[nums[i]])
    //             return nums[i];

    //         visited[nums[i]] = true;
    //     }

    //     return -1;
    // }

    // int findDuplicate(vector<int>& nums) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     for(int i=0; i<n; i++){

    //         int idx = abs(nums[i]);

    //         if(nums[idx] < 0)
    //             return idx;

    //         nums[idx] = -nums[idx];
    //     }
        

    //     return -1;
    // }

    int findDuplicate(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int fast = nums[0];
        int slow = nums[0];

        while(true){

            fast = nums[nums[fast]];
            slow = nums[slow];

            if(fast == slow)
                break;
        } 

        fast = nums[0];

        while(fast != slow){

            fast = nums[fast];
            slow = nums[slow];
        }

        return slow;   
    }
};