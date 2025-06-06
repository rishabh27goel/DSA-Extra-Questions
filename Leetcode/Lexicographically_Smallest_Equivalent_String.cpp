#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int findParent(int character, vector<int> &parent) {
          if(parent[character] == character)
              return character;
  
          return parent[character] = findParent(parent[character], parent);
      }
  
      string smallestEquivalentString(string s1, string s2, string baseStr) {
          int size = s1.size();
  
          vector<int> parent;
          for(int idx = 0; idx < 26; idx++) {
              parent.push_back(idx);
          }
  
          for(int idx = 0; idx < size; idx++) {
              int parentOne = findParent(s1[idx]-'a', parent);
              int parentTwo = findParent(s2[idx]-'a', parent);
              
              if(parentOne != parentTwo) {
                  parent[max(parentOne, parentTwo)] = min(parentOne, parentTwo);
              }
          }
  
          for(int idx = 0; idx < 26; idx++) {
              int p = findParent(idx, parent);
              parent[idx] = p;
          }
  
          string mapping = "";
          for(int idx = 0; idx < baseStr.size(); idx++) {
              int chIdx = parent[(baseStr[idx]-'a')];
              mapping.push_back((char) (chIdx + 'a'));
          }
  
          return mapping;
      }
  };