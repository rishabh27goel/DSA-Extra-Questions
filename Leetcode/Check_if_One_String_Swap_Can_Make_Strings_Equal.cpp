#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();

        int idxA = -1;
        int idxB = -1;

        for(int j = 0; j < n; j++) {
            if(s1[j] != s2[j]) {
                if(idxA != -1 && idxB != -1) {
                    return false;
                }
                
                if(idxA == -1) {
                    idxA = j;
                }
                else if(idxB == -1) {
                    idxB = j;
                }   
            }
        }

        // Strings are equal
        if(idxA == -1 && idxB == -1)
            return true;

        // If only one character is different
        if(idxA == -1 || idxB == -1)
            return false;

        // Checking if the changed chars are equal in both the strings
        if(s1[idxA] == s2[idxB] && s1[idxB] == s2[idxA])
            return true;

        return false;
    }
};