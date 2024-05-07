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

    ListNode* doubleIt(ListNode* head) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        head = reverseList(head);
    
        ListNode* start = head;
        ListNode* lastNode = NULL;
        int carry = 0;

        while(start != NULL){
            
            int number = 0;
            if(start != NULL)
                number = start->val;
        
            int mul = (2 * number) + carry;
            
            start->val = (mul % 10);
            carry = mul / 10;

            lastNode = start;
            start = start->next;
        }

        if(carry != 0){
            ListNode* node = new ListNode(carry);
            lastNode->next = node;
        }

        head = reverseList(head);
        return head;
    }
};