#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> result;
        for(int i=0; i<n-2; i++){

            vector<int> sub;
            for(int j=0; j<m-2; j++){

                int maxVal = 0;
                for(int x=0; x<3; x++){
                    for(int y=0; y<3; y++){

                        if(i + x < n && j + y < m){
                            maxVal = max(grid[i + x][j + y], maxVal);
                        }
                    }
                }
                sub.push_back(maxVal);
            }
            result.push_back(sub);
        }

        return result;
    }
};