#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> result;

        if(n == 0)
            return {0};


        int x = 1;
        result.push_back(0);
        
        for(int i=1; i<=n; i++){

            if(i == x){

                result.push_back(1);
                x <<= 1;
            }
            else{

                result.push_back(1 + result[i - (x >> 1)]);
            }
        }

        return result;
    }
};