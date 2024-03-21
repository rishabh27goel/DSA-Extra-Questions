#include <vector>
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        ListNode* start = NULL;
        ListNode* itr1 = list1;
        int idx = 0;

        while(idx < b){

            if(idx == a-1)
                start = itr1;

            idx++;
            itr1 = itr1->next;
        }

        ListNode* itr2 = list2;
        start->next = list2;

        while(itr2->next != NULL){
            itr2 = itr2->next;
        }

        itr2->next = itr1->next;
        return list1;
    }
};