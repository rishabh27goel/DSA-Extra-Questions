#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Method 1 : 
    // vector<vector<int>> generate(int numRows) {
        
    //     vector<vector<int>> result;

    //     for(int i=0; i<numRows; i++){

    //         vector<int> sub;
    //         sub.push_back(1);

    //         for(int j=1; j<i; j++){

    //             sub.push_back(result[i-1][j-1] + result[i-1][j]);
    //         }

    //         if(i > 0)
    //             sub.push_back(1);


    //         result.push_back(sub);
    //     }

    //     return result;
    // }

    // Method 2 :
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result;

        for(int i=1; i<=numRows; i++){

            vector<int> sub;
            int c = 1;

            for(int j=1; j<i; j++){

                sub.push_back(c);

                c *= (i - j);
                c /= j;
            }

            sub.push_back(c);
            result.push_back(sub);
        }

        return result;
    }
};