#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int size = dominoes.size();
    
            vector<int> count(100, 0);
            int maxNums = 0;
    
            for(int idx = 0; idx < size; idx++) {
                int one = dominoes[idx][0];
                int two = dominoes[idx][1];
    
                int key = (one < two ? one * 10 + two : two * 10 + one);
                maxNums += count[key]++;
            }
    
            return maxNums;
        }
    };