#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int countCharacters(vector<string>& words, string chars) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = words.size();

        int charCount[26] = {0};

        for(int i=0; i<chars.size(); i++){

            charCount[chars[i]-'a']++;
        }


        int result = 0;

        for(int i=0; i<n; i++){

            int tmp[26] = {0};

            for(int j=0; j<words[i].size(); j++){

                tmp[words[i][j]-'a']++;
            }


            bool good = true;

            for(int j=0; j<26; j++){

                if(tmp[j] == 0)
                    continue;

                if(tmp[j] > charCount[j]){

                    good = false;
                    break;
                }
            }

            if(good)
                result += (int) words[i].size();
        }

        return result;
    }
};