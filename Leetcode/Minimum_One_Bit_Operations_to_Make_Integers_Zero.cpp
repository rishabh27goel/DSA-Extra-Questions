#include <iostream>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> f(32, 0);
        f[0] = 1;

        for(int i=1; i<31; i++){

            f[i] = 2 * f[i-1] + 1;
        }

        int result = 0;
        int c = 0;

        for(int i=31; i>=0; i--){

            if(n & (1 << i)){

                c++;

                if(c & 1){

                    result += f[i];
                }
                else{

                    result -= f[i];
                }
            }
        }

        return result;
    }
};