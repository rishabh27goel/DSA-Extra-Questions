#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // vector<int> decrypt(vector<int>& code, int k) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = code.size();

    //     vector<int> result;
    //     for(int i = 0; i < n; i++) {
    //         if(k == 0) {
    //             result.push_back(0);
    //         }
    //         else if(k > 0) {
    //             int total = 0;
    //             for(int j = 1; j <= k; j++) {
    //                 total += code[(i + j) % n];
    //             }
    //             result.push_back(total);
    //         }
    //         else {
    //             int total = 0;
    //             for(int j = 1; j <= -k; j++) {
    //                 total += code[(i - j + n) % n];
    //             }
    //             result.push_back(total);
    //         }
    //     }

    //     return result;
    // }

    vector<int> decrypt(vector<int>& code, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = code.size();

        if(k == 0)
            return vector<int> (n, 0);

        if(k > 0) {
            vector<int> result(n);
            int windowSum = 0;
            int i = 0;
            int j = 0;

            while(i < n) {
                windowSum += code[j % n];
                if(j - i == k)  windowSum -= code[i++];

                if(j - k >= 0)  result[j - k] = windowSum;
                j++;
            }

            return result;
        }
        else {
            vector<int> result(n);
            int windowSum = 0;
            int i = 0;
            int j = 0;
            k = -k;

            while(i < n) {
                windowSum += code[j % n];
                if(j - i == k)  windowSum -= code[i++];

                if(j - k >= 0)  result[(j + 1) % n] = windowSum;
                j++;
            }

            return result;
        }      
    }
};