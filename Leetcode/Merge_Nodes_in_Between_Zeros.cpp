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
    ListNode* mergeNodes(ListNode* head) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        ListNode* itr = head->next;
        while(itr != NULL){
        
            ListNode* start = itr;
            int total = 0;

            while(start != NULL && start->val != 0){
                total += start->val;
                start = start->next;
            }

            ListNode* nextNode = start->next;
            if(newHead == NULL) {
                newHead = itr;
            }
            else {
                newTail->next = itr;
            }

            newTail = itr;
            newTail->val = total;
            itr = nextNode;
        }

        newTail->next = NULL;
        return newHead;
    }
};