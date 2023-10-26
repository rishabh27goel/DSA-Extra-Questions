#include <iostream>
using namespace std;

class Solution {
public:

    int findKthHelper(int n, int k){

        // As root is 0
        if(n == 1)
            return 0;

        int totalNodes = pow(2, (n-1));

        // If right side 
        if(totalNodes / 2 < k){

            return !findKthHelper(n-1, k - (totalNodes / 2));
        }
        else {

            return findKthHelper(n-1, k);
        }
    }

    int kthGrammar(int n, int k) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        return findKthHelper(n, k);
    }
};