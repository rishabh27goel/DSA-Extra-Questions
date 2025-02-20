#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        // int getConvertedNumber(int numSize, string &binaryStr) {
        //     int currNumber = 0;
        //     int mask = 1;
    
        //     for(int idx = numSize - 1; idx >= 0; idx--) {
        //         if(binaryStr[idx] == '1') {
        //             currNumber += mask;
        //         }
        //         mask <<= 1;
        //     }
    
        //     return currNumber;
        // }
    
        // string findDifferentBinaryString(vector<string>& nums) {
        //     int numSize = nums.size();
        //     int size = (1 << numSize);
    
        //     vector<bool> visitedNumbers(size, false);
        //     for(int numIdx = 0; numIdx < numSize; numIdx++) {
        //         int currNum = getConvertedNumber(numSize, nums[numIdx]);
        //         visitedNumbers[currNum] = true;
        //     }
    
        //     for(int idx = 0; idx < size; idx++) {
        //         if(visitedNumbers[idx])  continue;
    
        //         string str = "";
        //         int number = idx;
    
        //         for(int bit = numSize - 1; bit >= 0; bit--) {
        //             str.push_back(((1 << bit) & number) ? '1' : '0');
        //         }
    
        //         return str;
        //     }
    
        //     return "";
        // }
    
        int getConvertedNumber(int numSize, string &binaryStr) {
            int currNumber = 0;
            int mask = 1;
    
            for(int idx = numSize - 1; idx >= 0; idx--) {
                if(binaryStr[idx] == '1') {
                    currNumber += mask;
                }
                mask <<= 1;
            }
    
            return currNumber;
        }
    
        string findDifferentBinaryString(vector<string>& nums) {
            int numSize = nums.size();
            
            string binaryStr = "";
            for(int idx = 0; idx < numSize; idx++) {
                binaryStr.push_back((nums[idx][idx] == '0') ? '1' : '0');
            }
            return binaryStr;
        }
    };