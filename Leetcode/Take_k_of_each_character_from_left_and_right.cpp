#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Brute Force
    // int result = INT_MAX;
    // void findCharTake(int n, string &str, int k, vector<int> &charCount, int left, int right, int operations) {
    //     if(charCount[0] >= k && charCount[1] >= k && charCount[2] >= k)
    //         result = min(result, operations);
        
    //     if(left > right)         
    //         return;

    //     // Take from left
    //     charCount[str[left]-'a']++;
    //     findCharTake(n, str, k, charCount, left + 1, right, operations + 1);
    //     charCount[str[left]-'a']--;

    //     // Take from right
    //     charCount[str[right]-'a']++;
    //     findCharTake(n, str, k, charCount, left, right - 1, operations + 1);
    //     charCount[str[right]-'a']--;
    // }

    // int takeCharacters(string str, int k) {
    //     int n = str.size();

    //     vector<int> charCount(3, 0);
    //     findCharTake(n, str, k, charCount, 0, n-1, 0);

    //     return result == INT_MAX ? -1 : result;
    // }

    // Target : Minimum subarray having count of all chars >= k (a >= k && b >= k && c >= k)
    // Alternative: Maximum window having (a < k || b < k || c < k)
    int takeCharacters(string str, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = str.size();

        int charCount[3] = {0};
        for(int j = 0; j < n; j++) 
            charCount[str[j]-'a']++;

        if(charCount[0] < k || charCount[1] < k || charCount[2] < k)
            return -1;

        int windowSize = n;
        int start = 0;
        int end = 0;

        while(end < n) {
            charCount[str[end]-'a']--;

            while(start <= end && (charCount[0] < k || charCount[1] < k || charCount[2] < k)) {
                charCount[str[start]-'a']++;
                start++;
            }

            windowSize = min(windowSize, n - (end - start + 1));
            end++;
        }

        return windowSize;        
    }
};