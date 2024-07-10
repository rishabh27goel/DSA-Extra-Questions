#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = logs.size();

        int depth = 0;
        for(int i=0; i<n; i++){
            if(logs[i][0] == '.'){
                if(logs[i][1] == '.'){
                    depth = max(0, depth - 1);
                }
            }
            else {
                depth += 1;
            }
        }

        return depth;
    }
};