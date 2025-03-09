#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      /*
          As the array is circular 
          For array : 0 1 0 1 0 1 0 1 
                      0 1 2 3 4 5 6 7
  
          k = 3
          0 1 2, 1 2 3, 2 3 4, 3 4 5, 4 5 6, 5 6 7, 6 7 0, 7 0 1
      */
  
      int numberOfAlternatingGroups(vector<int>& colors, int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = colors.size();
  
          int groupsCount = 0;
          int windowSize = 0;
  
          for(int colorIdx = 0; colorIdx < size + k - 1; colorIdx++) {
              if(colors[colorIdx % size] != colors[(colorIdx + size - 1) % size])
                  windowSize++;
              else 
                  windowSize = 1;
              
              if(windowSize >= k)
                  groupsCount++;
          }
  
          return groupsCount;
      }
  };