#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = s.size();

        int result = n;
        int aCount = 0;
        int bCount = 0;

        for(int i=0; i<n; i++){
            aCount += (s[i] == 'a');
            bCount += (s[i] == 'b');
        }

        if(aCount == 0 || bCount == 0)
            return 0;

        int tmpA = aCount;
        int tmpB = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'a'){
                tmpA--;
            }
            else {
                if(tmpA == 0)  break;
                result = min(result, tmpA + tmpB);
                tmpB++;
            }
        }
        
        tmpA = 0;
        tmpB = bCount;
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'b'){
                tmpB--;
            }
            else {
                if(tmpB == 0)  break;
                result = min(result, tmpA + tmpB);
                tmpA++;
            }
        }

        return result == n ? 0 : result;
    }
};