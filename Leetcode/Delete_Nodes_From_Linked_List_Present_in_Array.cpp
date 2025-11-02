#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    void addNode(ListNode* &head, ListNode* &tail, ListNode* &node) {
        if(head == NULL) head = node;
        else tail->next = node;
        tail = node;
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);
        
        unordered_set<int> numSet(nums.begin(), nums.end());

        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        ListNode* itr = head;
        while(itr != NULL) {
            if(numSet.find(itr->val) == numSet.end()) 
                addNode(newHead, newTail, itr);

            itr = itr->next;
        }

        if(newTail != NULL) newTail->next = NULL;
        return newHead;
    }
};