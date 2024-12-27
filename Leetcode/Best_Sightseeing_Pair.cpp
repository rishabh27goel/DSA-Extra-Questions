#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int maxScore = INT_MIN;
        int maxNum = INT_MIN;

        for(int j = 0; j < n; j++) {
            if(maxNum != INT_MIN)
                maxScore = max(maxScore, maxNum + values[j] - j);

            maxNum = max(values[j] + j, maxNum);
        }

        return maxScore;
    }
};