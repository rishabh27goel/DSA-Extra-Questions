#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    // void findNextSmaller(vector<int> &nums, vector<int> &result){

    //     int n = nums.size();

    //     stack<int> st;

    //     for(int i=n-1; i>=0; i--){

    //         while(!st.empty() && nums[st.top()] >= nums[i]){

    //             st.pop();
    //         }

    //         if(st.empty()){

    //             result[i] = n;
    //         }
    //         else{

    //             result[i] = st.top();
    //         }

    //         st.push(i);
    //     }
    // }

    // void findPrevSmaller(vector<int> &nums, vector<int> &result){

    //     int n = nums.size();

    //     stack<int> st;

    //     for(int i=0; i<n; i++){

    //         while(!st.empty() && nums[st.top()] >= nums[i]){

    //             st.pop();
    //         }

    //         if(st.empty()){

    //             result[i] = -1;
    //         }
    //         else{

    //             result[i] = st.top();
    //         }

    //         st.push(i);
    //     }
    // }

    // int maximumScore(vector<int>& nums, int k) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     vector<int> nextSmaller(n);
    //     vector<int> prevSmaller(n);

    //     findNextSmaller(nums, nextSmaller);
    //     findPrevSmaller(nums, prevSmaller);


    //     int maxScore = 0;

    //     for(int i=0; i<n; i++){

    //         int left = prevSmaller[i] + 1;
    //         int right = nextSmaller[i] - 1;

    //         if(left <= k && k <= right)
    //             maxScore = max((right - left + 1) * nums[i], maxScore);
    //     }

    //     return maxScore;
    // }

    int maximumScore(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        int result = nums[k];
        int currMin = nums[k];

        int left = k;
        int right = k;

        while(left > 0 || right < n-1){

            if((left > 0 ? nums[left-1] : 0) < (right < n-1 ? nums[right+1] : 0)){

                right++;
                currMin = min(nums[right], currMin);
            }
            else {

                left--;
                currMin = min(nums[left], currMin);
            }

            result = max((right - left + 1) * currMin, result);
        }


        return result;
    }
};