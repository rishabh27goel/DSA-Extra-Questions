#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    // string minRemoveToMakeValid(string s) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = s.size();

    //     stack<int> st;
    //     for(int i=0; i<n; i++){
    //         if(s[i] == '('){
    //             st.push(i);
    //         }
    //         else if(s[i] == ')'){
    //             if(!st.empty() && s[st.top()] == '('){
    //                 st.pop();
    //             }
    //             else {
    //                 st.push(i);
    //             }
    //         }
    //     }

    //     for(int i=n-1; i>=0; i--){ 
    //         if(!st.empty() && st.top() == i){
    //             s[i] = '#';
    //             st.pop();
    //         }
    //     }

    //     string result = "";
    //     for(int i=0; i<n; i++){
    //         if(s[i] != '#')
    //             result += s[i];
    //     }

    //     return result;
    // }

    string minRemoveToMakeValid(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        stack<int> st;
        for(int i=n-1; i>=0; i--){
            if(s[i] == ')'){
                st.push(i);
            }
            else if(s[i] == '('){
                if(!st.empty() && s[st.top()] == ')'){
                    st.pop();
                }
                else {
                    st.push(i);
                }
            }
        }

        string result = "";
        for(int i=0; i<n; i++){
            if(!st.empty() && st.top() == i) {
                st.pop();
                continue;
            }

            result += s[i];
        }

        return result;
    }
};