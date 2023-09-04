#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        ListNode* first = head;
        ListNode* second = head;

        while(second != NULL && second->next != NULL){

            first = first->next;
            second = second->next->next;

            if(first == second)
                return true;
        }

        return false;
    }
};