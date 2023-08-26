#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int dp[101][101];

    bool findInterleave(int n1, int n2, int n3, string &s1, string &s2, string &s3, int i, int j, int k){

        // Base Case
        if(i == n1){

            for(int z=j; z<n2 && k<n3; z++, k++){

                if(s2[z] != s3[k])
                    return false;
            }

            return true;
        }

        if(j == n2){

            for(int z=i; z<n1 && k<n3; z++, k++){

                if(s1[z] != s3[k])
                    return false;
            }

            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];


        bool match = false;

        // Chars are same
        if(s1[i] == s3[k] && s2[j] == s3[k]){

            bool call1 = findInterleave(n1, n2, n3, s1, s2, s3, i+1, j, k+1);
            bool call2 = findInterleave(n1, n2, n3, s1, s2, s3, i, j+1, k+1);

            match = (match || call1 || call2);
        }
        if(s1[i] == s3[k]){

            bool call = findInterleave(n1, n2, n3, s1, s2, s3, i+1, j, k+1);

            match = match || call;
        }
        else if(s2[j] == s3[k]){

            bool call = findInterleave(n1, n2, n3, s1, s2, s3, i, j+1, k+1);

            match = match || call;
        }

        return dp[i][j] = match;
    }

    bool isInterleave(string s1, string s2, string s3) {

        ios_base::sync_with_stdio(false);

        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        if(n1 + n2 != n3)
            return false;


        memset(dp, -1, sizeof(dp));

        return findInterleave(n1, n2, n3, s1, s2, s3, 0, 0, 0);
    }
};