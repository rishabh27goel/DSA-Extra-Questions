#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool hasSameDigits(string s) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          string currS = s;
          while(currS.size() > 2) {
              string nextS = "";
              for(int idx = 0; idx < currS.size() - 1; idx++) {
                  int numOne = currS[idx] - '0';
                  int numTwo = currS[idx + 1] - '0';
                  nextS.push_back((char) ('0' + (numOne + numTwo) % 10));
              }
              currS = nextS;
          }
          return currS[0] == currS[1];
      }
  };