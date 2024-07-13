#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = positions.size();

        vector<int> info;
        for(int i=0; i<n; i++){
            info.push_back(i);
        }

        sort(info.begin(), info.end(), [&](int i, int j){
            return positions[i] < positions[j];
        });

        vector<int> st;
        for(auto curr : info){
            if(directions[curr] == 'R'){
                st.push_back(curr);
            }
            else {
                while(!st.empty() && healths[curr] > 0){
                    int top = st.back();
                    st.pop_back();

                    if(healths[top] == healths[curr]) {
                        healths[top] = healths[curr] = 0;
                    }
                    else if(healths[top] > healths[curr]) {
                        healths[top] -= 1;
                        healths[curr] = 0;
                        st.push_back(top);
                    }
                    else {
                        healths[top] = 0;
                        healths[curr] -= 1;
                    }
                }
            }
        }

        vector<int> result;
        for(int i=0; i<n; i++){
            if(healths[i] > 0)
                result.push_back(healths[i]);
        }

        return result;
    }
};