#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int n = word.size();

        int j = 0;

        while(j < n){
            if(word[j] == ch){
                int start = 0;
                int end = j;

                while(start < end){
                    swap(word[start], word[end]);
                    start++;
                    end--;
                }
                
                break;
            }
            j++;
        }

        return word;
    }
};