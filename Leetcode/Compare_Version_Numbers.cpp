#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      void getRevisionArray(string version, vector<int> &revision) {
          int currIdx = 0;
          while(currIdx < version.size()) {
              if(version[currIdx] == '.') {
                  currIdx++;
              }
              else {
                  int number = 0;
                  while(currIdx < version.size() && version[currIdx] != '.') {
                      number = (number * 10) + (version[currIdx]-'0');
                      currIdx++;
                  }
                  revision.push_back(number);
              }
          }
      }
  
      int compareVersion(string version1, string version2) {
          vector<int> revisionOne;
          vector<int> revisionTwo;
  
          getRevisionArray(version1, revisionOne);
          getRevisionArray(version2, revisionTwo);
          
          int oneIdx = 0;
          int twoIdx = 0;
  
          while(oneIdx < revisionOne.size() || twoIdx < revisionTwo.size()) {
              int revOne = 0;
              if(oneIdx < revisionOne.size()) {
                  revOne = revisionOne[oneIdx];
                  oneIdx++;
              }
  
              int revTwo = 0;
              if(twoIdx < revisionTwo.size()) {
                  revTwo = revisionTwo[twoIdx];
                  twoIdx++;
              }
  
              if(revOne < revTwo) 
                  return -1;
  
              if(revOne > revTwo) 
                  return 1;
          }
          return 0;
      }
  };