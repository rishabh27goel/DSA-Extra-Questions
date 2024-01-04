#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = bank.size();

        int total = 0;
        int prevRow = 0;

        for(int i=0; i<n; i++){

            int c = 0;

            for(int j=0; j<bank[i].size(); j++){

                c += (bank[i][j] == '1');
            }

            if(c != 0){
                total += (prevRow * c);
                prevRow = c;
            }
        }

        return total;
    }
};