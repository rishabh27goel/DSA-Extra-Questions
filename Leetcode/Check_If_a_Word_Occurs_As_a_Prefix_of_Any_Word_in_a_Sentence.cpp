#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int m = searchWord.size();

        int wordCounter = 0;
        int i = 0;

        while(i < n) {
            if(sentence[i] == ' ') {
                i++;
            }
            else {
                int j = 0;
                while(i < n && j < m && sentence[i] == searchWord[j]) {
                    i++;
                    j++;
                }

                while(i < n && sentence[i] != ' ') {
                    i++;
                }

                wordCounter++;
                if(j == m)  return wordCounter;
            }
        }

        return -1;
    }
};