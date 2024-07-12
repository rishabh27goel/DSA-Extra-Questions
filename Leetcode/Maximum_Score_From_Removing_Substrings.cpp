#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int maximumGain(string s, int x, int y) {
        
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = s.size();

    //     string start = (x > y ? "ab" : "ba");
    //     if(x < y)   swap(x, y);

    //     string st = "";
    //     int result = 0;

    //     for(int i=0; i<n; i++){
    //         if(s[i] == start[1] && !st.empty() && st.back() == start[0]){
    //             result += x;
    //             st.pop_back();
    //         }
    //         else {
    //             st.push_back(s[i]);
    //         }            
    //     }

    //     string track = "";
    //     for(int i=0; i<st.size(); i++){
    //         if(st[i] == start[0] && !track.empty() && track.back() == start[1]){
    //             result += y;
    //             track.pop_back();
    //         }     
    //         else {
    //             track.push_back(st[i]);
    //         }    
    //     }

    //     return result;
    // }

    int findPoints(string &str, int high, int low, string pair){

        int n = str.size();
        int result = 0;

        int firstCount = 0;
        int secondCount = 0;

        for(int i=0; i<n; i++){
            if(str[i] == pair[0]){
                firstCount++;
            }
            else if(str[i] == pair[1]){
                if(firstCount > 0){
                    firstCount--;
                    result += high;
                }
                else {
                    secondCount++;
                }
            }
            else {
                result += (min(firstCount, secondCount) * low);
                firstCount = 0;
                secondCount = 0;
            }
        }

        // Take the low count
        result += (min(firstCount, secondCount) * low);
        return result;
    }

    int maximumGain(string s, int x, int y) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if(x < y){
            return findPoints(s, y, x, "ba");
        }
        else {
            return findPoints(s, x, y, "ab");
        }
    }
};