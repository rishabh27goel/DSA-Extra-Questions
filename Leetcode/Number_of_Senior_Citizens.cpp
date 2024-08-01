#include <iostream>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = details.size();

        int total = 0;
        for(int i=0; i<n; i++){
            int number = (details[i][11]-'0') * 10;
            number += (details[i][12]-'0');

            if(number > 60)  total++;
        } 

        return total;  
    }
};