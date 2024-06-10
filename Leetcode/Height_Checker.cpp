#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        int n = heights.size();

        int freq[101] = {0};
        for(int i=0; i<n; i++){
            freq[heights[i]]++;
        }

        int result = 0;
        int j = 0;

        for(int i=1; i<101; i++){
            if(freq[i] == 0)
                continue;

            while(freq[i]--){
                if(i != heights[j]){
                    result++;
                }
                j++;
            }
        }

        return result;
    }
};