#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
      int getDecimalValue(ListNode* head) {
          ListNode* itr = head;
          int decimal = 0;
  
          while(itr != NULL) {
              decimal <<= 1;
              decimal |= itr->val;
              itr = itr->next;
          }
  
          return decimal;
      }
  };