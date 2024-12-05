#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int m = target.size();

        int i = 0;
        int j = 0;

        while(true) {
            while(i < n && start[i] == '_') {
                i++;
            }

            while(j < m && target[j] == '_') {
                j++;
            }

            if(i == n && j == m)
                return true;

            else if(i == n || j == m)
                return false;

            else {
                if(start[i] != target[j])
                    return false;

                else if(start[i] == 'L' && target[j] == 'L' && j > i)
                    return false;

                else if(start[i] == 'R' && target[j] == 'R' && j < i)
                    return false;

                i++;
                j++;
            }
        }

        return true;
    }
};