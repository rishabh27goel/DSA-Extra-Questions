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

    ListNode* reverseList(ListNode* head){ 
    
        ListNode* prev = NULL;
        ListNode* store = NULL;

        while(head->next != NULL){
            store = head->next;
            head->next = prev;
            prev = head;
            head = store;
        }

        head->next = prev;
        return head;
    }

    ListNode* removeNodes(ListNode* head) {
        
        ios_base::sync_with_stdio(false);

        ListNode* start = reverseList(head);

        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        int largest = start->val;

        while(start != NULL){

            if(largest <= start->val){
                
                if(newHead == NULL){
                    newHead = start;
                }
                else {
                    newTail->next = start;
                }

                newTail = start;
                largest = start->val;
            }
          
            start = start->next;
        }

        newTail->next = NULL;
        newHead = reverseList(newHead);
        
        return newHead;
    }
};