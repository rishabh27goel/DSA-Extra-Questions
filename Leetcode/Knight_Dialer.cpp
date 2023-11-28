#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    const int mod = 1e9 + 7;

    int knightDialer(int n) {
        
        if(n == 1)
            return 10;

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<string> mapping = {"46", "68", "79", "48", "039", "", "017", "26", "13", "24"};

        int result = 0;
        vector<int> ways(10, 1);
        vector<int> temp(10, 0);

        for(int i=2; i<=n; i++){

            for(int j=0; j<10; j++){

                temp[j] = 0;

                for(char &ch : mapping[j]){

                    temp[j] = (temp[j] + ways[ch-'0']) % mod;
                }

                if(i == n)
                    result = (result + temp[j]) % mod;
            }

            ways = temp;
        }

        return result;
    }
};