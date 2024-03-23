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

        while(head->next != NULL){
            ListNode* store = head->next;
            head->next = prev;
            prev = head;
            head = store;
        }

        head->next = prev;
        return head;
    }

    bool isPalindrome(ListNode* head) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if(head->next == NULL)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;    
        }
    
        ListNode* middle = reverseList(slow->next);
        slow = head;

        while(middle != NULL){

            if(middle->val != slow->val)
                return false;

            slow = slow->next;
            middle = middle->next;
        }

        return true;
    }
};