#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validDistance(int n, vector<int> &position, int m, int dist){
        
        int balls = 1;
        int prev = position[0];
        
        for(int j=1; j<n; j++){
            if(position[j] >= dist + prev){
                balls++;
                prev = position[j];
                if(balls >= m)
                    return true;
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = position.size();

        sort(position.begin(), position.end());

        int result = -1;
        int start = 1;
        int end = 1e9 + 7;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(validDistance(n, position, m, mid)){
                result = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return result;
    }
};