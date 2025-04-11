#include <iostream>
using namespace std;

class Solution {
  public:
      int countSymmetricIntegers(int low, int high) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int integersCount = 0;  
          for(int current = low; current <= high; current++) {
              string str = to_string(current);  
              if(str.size() & 1)  continue;
  
              int firstHalfSum = 0;
              for(int idx = 0; idx < str.size() / 2; idx++) {
                  firstHalfSum += (str[idx] - '0');
              }
  
              int secondHalfSum = 0;
              for(int idx = str.size() / 2; idx < str.size(); idx++) {
                  secondHalfSum += (str[idx] - '0');
              }
  
              if(firstHalfSum == secondHalfSum)
                  integersCount++;
          }
          return integersCount;
      }
  };