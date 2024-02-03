#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        vector<int> result;
        vector<int> digits;
        int val = low;

        while(val != 0){
            digits.push_back(val % 10);
            val /= 10;
        }

        int j = digits.size();
        int start = digits[j-1];
        int number = 0;

        while(j--){
            number = (number * 10) + start;
            start++;
        }
        
        int highDigits = log10(high)+1;
        start = digits[digits.size()-1];
        start += (number < low);


        for(int len = digits.size(); len <= highDigits; len++){

            int j = (len == digits.size() ? start : 1);
            for(; j + len <= 10; j++){

                int size = len;
                int x = j;
                int number = 0;

                while(size--){

                    number = (number * 10) + x;
                    x++;
                }

                if(number > high)
                    break;

                result.push_back(number);
            }
        }

        return result;
    }
};