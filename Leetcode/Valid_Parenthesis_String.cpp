#include <iostream>
using namespace std;

class Solution {
public:

    // int dp[101][101];

    // bool findValid(int n, string &str, int idx, int c){

    //     // Base Case
    //     if(c < 0)
    //         return false;

    //     if(idx >= n)
    //         return c == 0;

    //     if(dp[idx][c] != -1)
    //         return dp[idx][c];

    //     bool valid = false;

    //     if(str[idx] == '(')
    //         valid = valid || findValid(n, str, idx + 1, c + 1);
    //     else if(str[idx] == ')')
    //         valid = valid || findValid(n, str, idx + 1, c - 1);
    //     else {
    //         valid = valid || findValid(n, str, idx + 1, c + 1);
    //         valid = valid || findValid(n, str, idx + 1, c - 1);
    //         valid = valid || findValid(n, str, idx + 1, c);
    //     }

    //     return dp[idx][c] = valid;
    // }

    // bool checkValidString(string s) {
    //     int n = s.size();

    //     memset(dp, -1, sizeof(dp));
    //     return findValid(n, s, 0, 0);
    // }

    bool checkValidString(string s) {
        int n = s.size();

        int opening = 0;
        int closing = 0;

        int i = 0;
        int j = n-1;

        while(i < n){

            if(s[i] == '(' || s[i] == '*'){
                opening++;
            }
            else {
                opening--;
            }

            if(s[j] == ')' || s[j] == '*'){
                closing++;
            }
            else {
                closing--;
            }

            if(opening < 0 || closing < 0)
                return false;

            i++;
            j--;
        }

        return true;
    }
};