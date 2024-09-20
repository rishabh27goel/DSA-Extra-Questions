#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // bool findPalindrome(int n, string &str, int i, int j) {
    //     while(i <= j) {
    //         if(str[i] != str[j])    return false;
    //         i++, j--;
    //     }
    //     return true;
    // }

    // string shortestPalindrome(string s) {
    //     if(s.size() == 0)
    //         return s;

    //     int n = s.size();

    //     int idx = -1;
    //     for(int j = 0; j < n; j++) {
    //         if(findPalindrome(n, s, 0, j)) {
    //             idx = j + 1;
    //         }
    //     }

    //     string front = s.substr(idx, n - idx);
    //     reverse(front.begin(), front.end());
    //     return front + s;
    // }

    int mod = 1e9 + 7;
    string shortestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if(s.size() == 0)   return s;

        int n = s.size();

        long base = 29;
        long power = 1;
        
        long prefix = 0;
        long suffix = 0;

        int end = -1;
        for(int j = 0; j < n; j++) {
            int idx = (s[j]-'a') + 1;

            prefix = (prefix + (idx * power) % mod) % mod;
            suffix = (idx + (base * suffix % mod)) % mod;

            if(prefix == suffix) 
                end = j + 1;
            
            power = (power * base) % mod;
        }
        
        string front = s.substr(end, n - end);
        reverse(front.begin(), front.end());
        return front + s;
    }
};