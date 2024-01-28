#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    // Better Force : [(n * m) ^ 3]

    // Time : O((n * m)^2) 
    // int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     for(int i=0; i<n; i++){

    //         int prefix = 0;
    //         for(int j=0; j<m; j++){

    //             prefix += matrix[i][j]; 
    //             matrix[i][j] = prefix;
    //         }
    //     }

    //     int result = 0;

    //     for(int colStart=0; colStart<m; colStart++){

    //         for(int colEnd=colStart; colEnd<m; colEnd++){
                
    //             for(int rowStart=0; rowStart<n; rowStart++){

    //                 int prefix = 0;
    //                 for(int rowEnd=rowStart; rowEnd<n; rowEnd++){
                    
    //                     prefix += (matrix[rowEnd][colEnd] - (colStart-1 >= 0 ? matrix[rowEnd][colStart-1] : 0));

    //                     if(prefix == target)
    //                         result++;
    //                 }   
    //             }
    //         }   
    //     }

    //     return result;
    // }

    // Time : O((n * m) * n) 
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++){

            int prefix = 0;
            for(int j=0; j<m; j++){

                prefix += matrix[i][j]; 
                matrix[i][j] = prefix;
            }
        }

        unordered_map<int, int> mp;
        int result = 0;

        for(int colStart=0; colStart<m; colStart++){

            for(int colEnd=colStart; colEnd<m; colEnd++){
                
                int prefix = 0;
                
                mp.clear();
                mp[0] = 1;
            
                for(int row=0; row<n; row++){

                    prefix += (matrix[row][colEnd] - (colStart-1 >= 0 ? matrix[row][colStart-1] : 0));
                    
                    result += mp[prefix-target];
                    mp[prefix]++;
                }
            }   
        }

        return result;
    }
};