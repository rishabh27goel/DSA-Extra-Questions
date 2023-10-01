#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = s.size();

        int i = 0;
        int j = 0;

        while(j < n){

            if(s[j] == ' '){

                j++;
                i = j;
            }
            else{

                while(j < n && s[j] != ' '){

                    j++;
                }


                int x = i;
                int y = j-1;

                while(x <= y){

                    swap(s[x], s[y]);
                    x++;
                    y--;
                }
            }
        }

        return s;
    }
};