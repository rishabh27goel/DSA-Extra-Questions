#include <iostream>
#include <vector>
using namespace std;

class FindSumPairs {
  private:
      unordered_map<int, int> numTwoMap;
      vector<int> numOne;
      vector<int> numTwo;
  
  public:
      FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
          ios_base::sync_with_stdio(false);
          cin.tie(NULL);
          cout.tie(NULL);
  
          for(int &currNum : nums1)
              numOne.push_back(currNum);
  
          for(int &currNum : nums2) {
              numTwoMap[currNum]++;
              numTwo.push_back(currNum);
          }
      }
      
      void add(int index, int val) {
          int prevValue = numTwo[index];
          numTwoMap[prevValue]--;
  
          numTwo[index] += val;
          numTwoMap[numTwo[index]]++;
      }
      
      int count(int tot) {
          int pairCount = 0;
          for(int &currNum : numOne)
              pairCount += numTwoMap[tot - currNum];
          
          return pairCount;
      }
  };
  
  /**
   * Your FindSumPairs object will be instantiated and called as such:
   * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
   * obj->add(index,val);
   * int param_2 = obj->count(tot);
   */