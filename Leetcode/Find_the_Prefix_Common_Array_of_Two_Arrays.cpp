#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = A.size();
        int m = B.size();

        long long one = 0;
        long long two = 0;

        vector<int> matches;
        for(int j = 0; j < n; j++) {
            one |= (1LL << A[j]);
            two |= (1LL << B[j]);

            long long mask = 1LL;
            int matchCount = 0;

            for(int k = 1; k <= 51; k++) {
                if((mask & one) && (mask & two))
                    matchCount++;

                mask <<= 1;
            }

            matches.push_back(matchCount);
        }

        return matches;
    }
};