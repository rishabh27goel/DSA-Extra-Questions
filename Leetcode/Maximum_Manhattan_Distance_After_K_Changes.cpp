#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int maxDistance(string str, int k) {
          int size = str.size();
  
          int distance = 0;
          int x = 0;
          int y = 0;
  
          for(int idx = 0; idx < size; idx++) {
              if(str[idx] == 'N')
                  y++;
  
              else if(str[idx] == 'S')
                  y--;
  
              else if(str[idx] == 'E')
                  x++;
                  
              else if(str[idx] == 'W')
                  x--;
  
              distance = max(distance, min(abs(x) + abs(y) + 2 * k, idx + 1));
          }
  
          return distance;
      }
  };