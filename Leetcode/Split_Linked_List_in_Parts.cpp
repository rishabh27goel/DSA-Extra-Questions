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

    void addNode(ListNode* &head, ListNode* &tail, ListNode* &itr){

        if(head == NULL){

            head = itr;
        }
        else{

            tail->next = itr;
        }

        tail = itr;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        ListNode* itr = head;
        int length = 0;
   
        while(itr != NULL){

            length++;
            itr = itr->next;
        }

        int fixLen = length / k;
        int remLen = length % k;

        
        vector<ListNode*> result;
        itr = head;

        while(k--){

            ListNode* newHead = NULL;
            ListNode* newTail = NULL;

            int c = fixLen;

            while(itr != NULL && c--){

                addNode(newHead, newTail, itr);
                itr = itr->next;
            }

            // Extra node
            if(itr != NULL && remLen > 0){

                addNode(newHead, newTail, itr);
                itr = itr->next;
                remLen--;
            }

            if(newTail != NULL)
                newTail->next = NULL;

            result.push_back(newHead);
        }

        return result;
    }
};