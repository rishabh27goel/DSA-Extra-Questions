#include <iostream>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = words.size();

        for(int i=0; i<n; i++){

            bool palin = true;
            int start = 0;
            int end = words[i].size()-1;

            while(start <= end){

                if(words[i][start] != words[i][end]){
                    palin = false;
                    break;
                }

                start++;
                end--;
            }

            if(palin)
                return words[i];
        }

        return "";
    }
};