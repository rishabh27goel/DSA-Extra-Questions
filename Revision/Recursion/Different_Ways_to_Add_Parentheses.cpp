#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Try creating the recursion map 
    // This will help us to find that every recursion call will return possible ways with all possible result
    vector<int> findPossibleWays(vector<int> &expArr, int start, int end) {
        if(start == end)
            return {expArr[start]};

        vector<int> result;
        for(int j = start; j <= end; j++) {
            if(j % 2 == 0)
                continue;

            vector<int> leftCalls = findPossibleWays(expArr, start, j - 1);
            vector<int> rightCalls = findPossibleWays(expArr, j + 1, end);

            char op = (char) expArr[j];
            for(int x = 0; x < leftCalls.size(); x++) {
                for(int y = 0; y < rightCalls.size(); y++) {
                    if(op == '-') {
                        result.push_back(leftCalls[x] - rightCalls[y]);
                    }
                    else if(op == '+') {
                        result.push_back(leftCalls[x] + rightCalls[y]);
                    }
                    else if(op == '*') {
                        result.push_back(leftCalls[x] * rightCalls[y]);
                    }
                }
            }
        }
        return result;
    }

    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();

        vector<int> expArr;
        int j = 0;

        while(j < n) {
            if(expression[j] >= '0' && expression[j] <= '9') {
                int number = 0;
                while(j < n && expression[j] >= '0' && expression[j] <= '9') {
                    number = ((number * 10) + (expression[j]-'0'));
                    j++;
                }
                expArr.push_back(number);
            }
            else {
                expArr.push_back(expression[j]);
                j++;
            }
        }
        return findPossibleWays(expArr, 0, expArr.size() - 1);
    }
};