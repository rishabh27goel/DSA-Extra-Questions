#include <iostream>
using namespace std;

class Solution {
    public:
        string largestGoodInteger(string num) {
            int size = num.size();
    
            int largest = -1;
            int currIdx = 0;
    
            while(currIdx < size) {
                char ch = num[currIdx];
                int count = 0;
    
                while(currIdx < size && ch == num[currIdx]) {
                    count++, currIdx++;
                }
    
                if(count >= 3 && largest < ch - '0')
                    largest = ch - '0';
            }
    
            if(largest == -1)
                return "";
    
            char ch = ('0' + largest);
            
            string str = "";
            str.push_back(ch);
            str.push_back(ch);
            str.push_back(ch);
            return str;
        }
    };