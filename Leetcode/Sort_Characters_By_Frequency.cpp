#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        int charCount[128] = {0};

        for(int i=0; i<n; i++){
            charCount[(int) s[i]]++;
        }

        vector<pair<int, char>> vt;

        for(int i=0; i<128; i++){
            
            if(charCount[i] != 0){

                vt.push_back({charCount[i], (char) i});
            }
        }

        sort(vt.begin(), vt.end());

        string result = "";

        for(int i=vt.size()-1; i>=0; i--){

            int c = vt[i].first;

            while(c--){
                result.push_back(vt[i].second);
            }
        }

        return result;
    }
};