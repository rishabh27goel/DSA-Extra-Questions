#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = dist.size();

        // Update the dist with dist / speed to get the time
        for(int i=0; i<n; i++){

            dist[i] = (int) ceil((float) dist[i] / (float) speed[i]);
        }

        // Sort by ascending order of time
        sort(dist.begin(), dist.end());


        int charge = 1;

        for(int i=1; i<n; i++){

            if(charge >= dist[i])
                break;

            charge++;
        }

        return charge;
    }
};