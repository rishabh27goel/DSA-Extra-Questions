#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
      priority_queue<string, vector<string>, greater<string>> smallestHeap; 
      void generateHappyString(int size, int k, string &happyStr) {
          if(size == 0) {
              smallestHeap.push(happyStr);
              return;
          }
  
          for(char ch = 'a'; ch <= 'c'; ch++) {
              if(happyStr.empty() || happyStr.back() != ch) {
                  happyStr.push_back(ch);
                  generateHappyString(size - 1, k, happyStr);
                  happyStr.pop_back();
              }
          }
      }
  
      string getHappyString(int n, int k) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          string happyStr = "";
          generateHappyString(n, k, happyStr);
  
          if(smallestHeap.size() < k)
              return "";
  
          while(--k) {
              smallestHeap.pop();
          }
  
          return smallestHeap.top();
      }
  
      // priority_queue<string> smallestHeap; 
      // void generateHappyString(int size, int k, string &happyStr) {
      //     if(size == 0) {
      //         smallestHeap.push(happyStr);
      //         if(smallestHeap.size() > k)
      //             smallestHeap.pop();
  
      //         return;
      //     }
  
      //     for(char ch = 'a'; ch <= 'c'; ch++) {
      //         if(happyStr.empty() || happyStr.back() != ch) {
      //             happyStr.push_back(ch);
      //             generateHappyString(size - 1, k, happyStr);
      //             happyStr.pop_back();
      //         }
      //     }
      // }
  
      // string getHappyString(int n, int k) {
      //     ios_base::sync_with_stdio(false);
      //     cin.tie(NULL);
      //     // cout.tie(NULL);
  
      //     string happyStr = "";
      //     generateHappyString(n, k, happyStr);
  
      //     if(smallestHeap.size() < k)
      //         return "";
  
      //     return smallestHeap.top();
      // }
  };