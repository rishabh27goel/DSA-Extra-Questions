#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();

        int total = 0;
        for(int i=0; i<n; i++){
    
            int row = 0;
            int pow = 1;

            for(int j=m-1; j>=0; j--){
                if(grid[i][j])
                    row += pow;

                pow <<= 1;
            }

            // Flip is needed
            if(grid[i][0] == 0) {
                total += (pow-1-row);
            }
            else {
                total += row;
            }
        }   

        int pow = 1;
        for(int j=m-1; j>=1; j--){            
            
            int c = 0;
            for(int i=0; i<n; i++){
                if(grid[i][0] == 1){
                    c += grid[i][j];
                }
                else {
                    c += !grid[i][j];
                }
            }

            // Flip column
            if(c < n-c){
                total -= (c * pow);
                total += ((n-c) * pow);
            }

            pow <<= 1;
        }

        return total;
    }
};