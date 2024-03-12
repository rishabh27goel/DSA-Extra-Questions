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
    ListNode* removeZeroSumSublists(ListNode* head) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        ListNode* itr = head;
        int prefix = 0;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> mp;
        mp[0] = dummy;

        while(itr != NULL){

            prefix += itr->val;

            if(mp.find(prefix) == mp.end()){
                mp[prefix] = itr;
            }
            else {
                ListNode* start = mp[prefix];
                int value = prefix;

                while(start != itr){
                    start = start->next;
                    value += start->val;

                    if(start != itr){
                        mp.erase(value);
                    }
                }

                ListNode* node = mp[prefix];
                node->next = start->next;
            }

            itr = itr->next;
        }

        head = dummy->next;
        delete dummy;

        return head;        
    }
};