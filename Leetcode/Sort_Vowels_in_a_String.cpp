#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isVowel(char ch) {
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                return true;
    
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                return true;
    
            return false;
        }
        string sortVowels(string str) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
    
            int size = str.size();
    
            int charCount[128] = {0};
            for(int idx = 0; idx < size; idx++) {
                if(isVowel(str[idx])) {
                    charCount[(int) str[idx]]++;
                }
            }
    
            int charIdx = 0;
            for(int idx = 0; idx < size; idx++) {
                if(isVowel(str[idx])) {
                    while(charIdx < 128 && charCount[charIdx] == 0)
                        charIdx++;
    
                    str[idx] = (char) charIdx;
                    charCount[charIdx]--;
                }
            }
            return str;
        }
    };