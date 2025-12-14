#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      bool codeCharCheck(char ch) {
          if(ch >= '0' && ch <= '9')   return true;
          if(ch >= 'a' && ch <= 'z')   return true;
          if(ch >= 'A' && ch <= 'Z')   return true;
          if(ch == '_')   return true;
          return false;
      }
      bool validBusinessLines(string &str) {
          if(str == "electronics")   return true;
          if(str == "grocery")       return true;
          if(str == "pharmacy")      return true;
          if(str == "restaurant")    return true;
          return false;
      }
  
      vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          int size = code.size();
  
          vector<int> validCoupon;
          for(int currIdx = 0; currIdx < size; currIdx++) {
              bool currentValid = true;
              currentValid = (currentValid && code[currIdx].size() > 0 && validBusinessLines(businessLine[currIdx]) && isActive[currIdx]);
  
              for(char currChar : code[currIdx]) {
                  if(!codeCharCheck(currChar)) 
                      currentValid = false;
              }
              if(currentValid)    validCoupon.push_back(currIdx);
          }
  
          sort(validCoupon.begin(), validCoupon.end(), [&](int idx1, int idx2) {
              if(businessLine[idx1] == businessLine[idx2])
                  return code[idx1] < code[idx2];
  
              return businessLine[idx1] < businessLine[idx2];
          });
  
          vector<string> validCodes;
          for(int currIdx = 0; currIdx < validCoupon.size(); currIdx++)
              validCodes.push_back(code[validCoupon[currIdx]]);
          
          return validCodes;
      }
  };