#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int trap(vector<int>& height) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = height.size();

    //     int result = 0;
    //     int maxVal = 0;

    //     vector<int> leftMax(n);
    //     for(int i=0; i<n; i++){
    //         leftMax[i] = maxVal = max(maxVal, height[i]);   
    //     }

    //     maxVal = 0;
    //     for(int i=n-1; i>=0; i--){
    //         maxVal = max(maxVal, height[i]);
    //         result += min(leftMax[i], maxVal) - height[i];
    //     }

    //     return result;
    // }

    int trap(vector<int>& height) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = height.size();

        int result = 0;
        int i = 0;
        int j = n-1;

        int leftMax = height[0];
        int rightMax = height[n-1];

        while(i < j){
        
            int current = 0;
            if(leftMax <= rightMax){
                current = max(0, leftMax - height[i]);
                i++;
            }
            else {
                current = max(0, rightMax - height[j]);
                j--;
            }

            result += current;
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);
        }

        return result;
    }
};