#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    int countPalindromicSubsequence(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        int result = 0;
        
        int first[26];
        int last[26];

        memset(first, -1, sizeof(first));
        memset(last, -1, sizeof(last));

        for(int i=0; i<n; i++){

            if(first[s[i]-'a'] == -1)
                first[s[i]-'a'] = i;

            last[s[i]-'a'] = i;
        }
        
        for(int i=0; i<26; i++){

            if(first[i] == -1 && last[i] == -1)
                continue;


            int left = first[i];
            int right = last[i];

            unordered_set<char> unique;

            for(int k=left+1; k<right; k++){

                unique.insert(s[k]);
            }   

            result += unique.size();
        }

        return result;
    }

    // int countPalindromicSubsequence(string s) {
        
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = s.size();

    //     int result = 0;
    //     unordered_set<char> letters;

    //     for(int i=0; i<n; i++){

    //         letters.insert(s[i]);
    //     }

    //     for(auto letter : letters){

    //         int first = -1;
    //         int last = -1;

    //         for(int k=0; k<n; k++){

    //             if(s[k] == letter){

    //                 if(first == -1)
    //                     first = k;

    //                 last = k;
    //             }
    //         }


    //         unordered_set<char> unique;

    //         for(int k=first+1; k<last; k++){

    //             unique.insert(s[k]);
    //         }   

    //         result += unique.size();
    //     }

    //     return result;
    // }
    
    // int countPalindromicSubsequence(string s) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = s.size();

    //     int left[26] = {0};
    //     int right[26] = {0};

    //     for(int i=0; i<n; i++){

    //         right[s[i]-'a']++;
    //     }

    //     map<pair<char, char>, bool> distinct;
    //     int result = 0;

    //     for(int i=0; i<n; i++){

    //         // Delete curr char
    //         right[s[i]-'a']--;
            
    //         for(int j=0; j<26; j++){

    //             if(left[j] != 0 && right[j] != 0){

    //                 if(distinct.find(make_pair(s[i], (char) (j + 'a'))) == distinct.end()){
    //                     distinct[make_pair(s[i], (char) (j + 'a'))] = true;
    //                     result++;
    //                 }
    //             }
    //         }

    //         // Update left for next iterations
    //         left[s[i]-'a']++;
    //     }

    //     return result;
    // }
};