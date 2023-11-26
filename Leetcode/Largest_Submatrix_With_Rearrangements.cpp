#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // int largestSubmatrix(vector<vector<int>>& matrix) {

    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     int result = 0;
    //     vector<pair<int, int>> prevHeights;

    //     for(int i=0; i<n; i++){

    //         vector<pair<int, int>> currHeights;
    //         vector<bool> seen(m, false);

    //         for(int j=0; j<prevHeights.size(); j++){

    //             // If current row column is 1
    //             if(matrix[i][prevHeights[j].second] == 1){

    //                 currHeights.push_back(make_pair(prevHeights[j].first + 1, prevHeights[j].second));
    //                 seen[prevHeights[j].second] = true;
    //             }
    //         }

    //         for(int j=0; j<m; j++){

    //             // If not seen in previous rows
    //             if(seen[j] == false && matrix[i][j] == 1){

    //                 currHeights.push_back(make_pair(1, j));
    //             }
    //         }

    //         // Update max vertical and horizontal
    //         for(int j=0; j<currHeights.size(); j++){

    //             result = max(currHeights[j].first * (j+1), result);
    //         }

    //         prevHeights = currHeights;
    //     }

    //     return result;
    // }


    // We have to minimize the matrix in order to find some sort of relation
    // Consider row by row

    // Time : O(n * m * log(m))  Space : O(m)
    int largestSubmatrix(vector<vector<int>>& matrix) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = matrix.size();
        int m = matrix[0].size();

        int result = 0;
        vector<int> row(m, 0);

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){

                // All the previous sum will not be considered
                if(matrix[i][j] == 0){

                    row[j] = 0;
                }
                else {

                    row[j] += matrix[i][j];
                }
            }

            vector<int> curr(row.begin(), row.end());
            sort(curr.begin(), curr.end(), greater<int> ());

            int minVal = n;

            for(int j=0; j<m; j++){
            
                minVal = min(minVal, curr[j]);
                result = max(result, minVal * (j+1));
            }
        }

        return result;
    }
};