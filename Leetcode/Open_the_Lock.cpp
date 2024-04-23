#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int m = deadends.size();

        unordered_set<string> st;
        for(int i=0; i<m; i++){
            st.insert(deadends[i]);
        }

        if(st.find("0000") != st.end())
            return -1;

        if(st.find(target) != st.end())
            return -1;

        int distance = 0;

        queue<string> q;
        q.push("0000");

        while(!q.empty()){

            int size = q.size();

            while(size--){

                string str = q.front();
                q.pop();

                if(str == target)
                    return distance;

                for(int k=0; k<4; k++){
                    char org =  str[k];

                    str[k] = (org == '9' ? '0' : (org + 1));
                    if(st.find(str) == st.end()){
                        q.push(str);
                        st.insert(str);
                    }

                    str[k] = (org == '0' ? '9' : (org - 1));
                    if(st.find(str) == st.end()){
                        q.push(str);
                        st.insert(str);
                    }

                    str[k] = org;
                }
            }

            distance++;
        }

        return -1;
    }
};