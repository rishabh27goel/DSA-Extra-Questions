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
    ListNode* reverseList(ListNode* head) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if(head == NULL)
            return NULL;

        ListNode* prev = NULL;
        ListNode* itr = head;

        while(itr->next != NULL){

            ListNode* nextNode = itr->next;
            itr->next = prev;
            prev = itr;
            itr = nextNode;
        }

        itr->next = prev;
        head = itr;
        return head;
    }
};