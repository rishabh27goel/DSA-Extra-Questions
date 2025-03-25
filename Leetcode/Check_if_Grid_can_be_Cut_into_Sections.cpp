#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      /*
          1. Grid N * N
          2. Origin at bottom - left corner
          3. Rectangle do not overlap
          4. 2 hori or 2 Verti -> 3 sections -> Atleast one rectangle
          5. Every rectagle -> One section
      */
  
      bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = rectangles.size();
  
          vector<pair<int, int>> horizontalRanges;
          vector<pair<int, int>> verticalRanges;
  
          for(int idx = 0; idx < size; idx++) {
              int x1 = rectangles[idx][0];
              int y1 = rectangles[idx][1];
              int x2 = rectangles[idx][2];
              int y2 = rectangles[idx][3];
  
              horizontalRanges.push_back(make_pair(x1, x2));
              verticalRanges.push_back(make_pair(y1, y2));
          }
  
          sort(horizontalRanges.begin(), horizontalRanges.end(), [&](auto &p1, auto &p2) {
              if(p1.first == p2.first)
                  return p1.second < p2.second;
  
              return p1.first < p2.first;
          });
          sort(verticalRanges.begin(), verticalRanges.end(), [&](auto &p1, auto &p2) {
              if(p1.first == p2.first)
                  return p1.second < p2.second;
  
              return p1.first < p2.first;
          });
  
          // Find number of merged intervals
          int horiStart = horizontalRanges[0].first;
          int horiEnd = horizontalRanges[0].second;
          int segments = 1;
  
          for(int idx = 1; idx < size; idx++) {
              if(horiEnd >  horizontalRanges[idx].first) {
                  horiStart = min(horiStart, horizontalRanges[idx].first);
                  horiEnd = max(horiEnd, horizontalRanges[idx].second);
              }
              else {
                  segments++;
                  horiStart = horizontalRanges[idx].first;
                  horiEnd = horizontalRanges[idx].second;
              }
          }
  
          if(segments > 2)   return true;
  
  
          int vertiStart = verticalRanges[0].first;
          int vertiEnd = verticalRanges[0].second;
          segments = 1;
  
          for(int idx = 1; idx < size; idx++) {
              if(vertiEnd >  verticalRanges[idx].first) {
                  vertiStart = min(vertiStart, verticalRanges[idx].first);
                  vertiEnd = max(vertiEnd, verticalRanges[idx].second);
              }
              else {
                  segments++;
                  vertiStart = verticalRanges[idx].first;
                  vertiEnd = verticalRanges[idx].second;
              }
          }
          
          if(segments > 2)   return true;
  
          return false; 
      }
  };