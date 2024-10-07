#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int minLength(string str) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = str.size();

    //     string prev = str;
    //     bool removed = true;

    //     while(removed) {
    //         string tmp = "";
    //         removed = false;

    //         for(int j = 0; j < prev.size(); j++) {
    //             if(!tmp.empty() && !removed && (prev[j] == 'D' && tmp.back() == 'C')) {
    //                 tmp.pop_back();
    //                 removed = true;
    //             }  
    //             else if(!tmp.empty() && !removed && (prev[j] == 'B' && tmp.back() == 'A')) {
    //                 tmp.pop_back();
    //                 removed = true;
    //             } 
    //             else {
    //                 tmp.push_back(prev[j]);
    //             }
    //         }  

    //         prev = tmp;
    //     }

    //     return prev.size();
    // }

    int minLength(string str) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = str.size();

        string tmp = "";
        for(int j = 0; j < str.size(); j++) {
            if(!tmp.empty() && tmp.back() == 'C' && str[j] == 'D')
                tmp.pop_back();
            else if(!tmp.empty() && tmp.back() == 'A' && str[j] == 'B')
                tmp.pop_back();
            else 
                tmp.push_back(str[j]);
        }

        return tmp.size();
    }
};