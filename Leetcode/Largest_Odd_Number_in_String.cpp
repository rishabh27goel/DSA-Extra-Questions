#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = num.size();
    
        int lastOdd = -1;
    
        for(int i=n-1; i>=0; i--){

            if((num[i]-'0') & 1){
              break;
            }
            else{
              num.pop_back();
            }
        }


        // string result = "";

        // for(int i=0; i<=lastOdd; i++){

        //     result.push_back(num[i]);
        // }

        return num;
    }
};