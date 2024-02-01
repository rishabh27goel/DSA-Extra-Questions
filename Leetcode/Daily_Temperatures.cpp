#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = temperatures.size();

        vector<int> result(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){

            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){

                st.pop();
            }

            if(st.empty()){
                result[i] = 0;
            }
            else {
                result[i] = (st.top() - i);
            }

            st.push(i);
        }

        return result;
    }
};