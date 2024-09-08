#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        ListNode* itr = head;
        int listSize = 0;
        
        while(itr != NULL) {
            listSize++;
            itr = itr->next;
        }

        vector<ListNode*> parts(k);
        itr = head;

        int fixed = listSize / k;
        int extra = listSize % k;
        int j = 0;

        while(itr != NULL) {
            int window = fixed + (extra-- > 0);

            ListNode* start = itr;
            ListNode* prevNode = NULL;

            while(window--) {
                prevNode = itr;
                itr = itr->next;
            }

            prevNode->next = NULL;
            parts[j] = start;
            j++;
        }

        return parts;
    }
};