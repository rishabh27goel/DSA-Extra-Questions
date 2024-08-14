#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> result;
        long val = 1;

        for(int i=1; i<=rowIndex+1; i++){

            result.push_back((int) val);
            val *= (rowIndex - i + 1);
            val /= i;
        }

        return result;
    }
};