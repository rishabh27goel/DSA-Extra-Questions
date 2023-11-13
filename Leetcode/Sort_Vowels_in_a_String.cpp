#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool isVowel(char ch){

        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;


        return false;
    }

    // string sortVowels(string s) {
        
    //     int n = s.size();

    //     string vowel = "";

    //     for(int i=0; i<n; i++){

    //         if(isVowel(s[i])){

    //             vowel.push_back(s[i]);
    //         }
    //     }

    //     sort(vowel.begin(), vowel.end());

    //     int j = 0;

    //     for(int i=0; i<n; i++){

    //         if(isVowel(s[i])){

    //             s[i] = vowel[j++];
    //         }
    //     }

    //     return s;
    // }

    string sortVowels(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        string vowel = "";
        vector<int> charCount(256, 0);

        for(int i=0; i<n; i++){

            if(isVowel(s[i])) {

                charCount[(int) s[i]]++;
            }
        }


        int j = 0;

        for(int i=0; i<n; i++){

            if(isVowel(s[i])){

                while(j < 256 && charCount[j] == 0){

                    j++;
                }

                s[i] = (char) j;
                charCount[j]--;
            }
        }

        return s;
    }
};