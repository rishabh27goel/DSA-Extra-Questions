#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // 5 10 10 20 5 10 10 5
    // 5 -> Count them
    // 10 -> give one 5 and count 10 
    // 20 -> 3-5 or 1-10 and 1-5 -> count 20 of no use
    // 5 count < 3 && 10 count < 1

    bool lemonadeChange(vector<int>& bills) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = bills.size();

        int five = 0;
        int ten = 0;

        for(int i=0; i<n; i++) {
            if(bills[i] == 5) {
                five++;
            }
            else if(bills[i] == 10) {
                if(five == 0)  
                    return false;

                five--;
                ten++;
            }
            else {
                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                } 
                else if(five >= 3){
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};