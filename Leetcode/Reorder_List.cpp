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

    void reorderList(ListNode* head) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if(head->next == NULL)
            return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = reverseList(slow->next);
        slow->next = NULL;
        slow = head;

        while(middle != NULL){

            ListNode* track1 = slow->next;
            ListNode* track2 = middle->next;

            slow->next = middle;
            middle->next = track1;

            slow = track1;
            middle = track2;
        }
    }
};