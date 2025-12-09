#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int countTriples(int n) {
//         int triplet = 0;
//         for(int a = 1; a <= n; a++) {
//             for(int b = 1; b <= n; b++) {
//                 for(int c = 1; c <= n; c++) {
//                     if(a * a + b * b == c * c)
//                         triplet++;
//                 }
//             }
//         }
//         return triplet;
//     }
// };

class Solution {
  public:
      int countTriples(int n) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int triplet = 0;
          for(int a = 1; a <= n; a++) {
              for(int b = 1; b <= n; b++) {
                  int sqC = (a * a + b * b);
                  int rootC = sqrt(sqC);
                  if((rootC * rootC == sqC) && rootC <= n)
                      triplet++;
              }
          }
          return triplet;
      }
  };