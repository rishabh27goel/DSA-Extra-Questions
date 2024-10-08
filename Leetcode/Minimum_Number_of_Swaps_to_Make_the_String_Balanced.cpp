#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(string str) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = str.size();

        int count = 0;
        for(int j = 0; j < n; j++) {
            if(str[j] == '[') {
                count++;
            }
            else {
                if(count > 0)  count--;
            }
        }

        return (count + 1) / 2;
    }
};