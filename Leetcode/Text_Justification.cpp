#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void addSpaces(string &str, int spaces){

        while(spaces--){

            str.push_back(' ');
        }
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = words.size();

        vector<string> result;
        int i = 0;

        int last = -1;
        int lastWC = -1;

        while(i < n){

            int start = i;
            int space = 1;
            int width = words[i++].size();

            while(i < n && width + words[i].size() + space <= maxWidth){

                width += words[i].size();
                space++;

                i++;
            }

            last = start;
            lastWC = space;

            string line = words[start++];
            int extraSpace = maxWidth - width;


            // Single Word
            if(space == 1){

                addSpaces(line, extraSpace);
            }
            else{

                int common = extraSpace / (space-1);
                int notCommon = extraSpace % (space-1);

                for(int j=start; j<start + space - 1; j++){

                    addSpaces(line, common);

                    if(notCommon-- > 0)
                        line += " ";

                    line += words[j]; 
                }
            }

            result.push_back(line);
        }

        // Remove last
        result.pop_back();

        string line = words[last++];

        while(last < n){

            line += " ";
            line += words[last++];
        }

        addSpaces(line, maxWidth - line.size());

        result.push_back(line);
        return result;
    }
};