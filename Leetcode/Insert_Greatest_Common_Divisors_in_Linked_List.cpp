#include <iostream>
#include <vector>
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
    int findGCD(int x, int y) {
        if(x == 0)
            return y;

        return findGCD(y % x, x);
    }

    void addNode(ListNode* &head, ListNode* &tail, ListNode* &node) {
        if(head == NULL) 
            head = node;
        else
            tail->next = node;

        tail = node;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL)
            return head;

        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        ListNode* itr = head->next;
        ListNode* prevNode = head;

        while(itr != NULL) {
            addNode(newHead, newTail, prevNode);
            ListNode* newNode = new ListNode(findGCD(prevNode->val, itr->val));
            addNode(newHead, newTail, newNode);

            prevNode = itr;
            itr = itr->next;
        }

        addNode(newHead, newTail, prevNode);
        return newHead;
    }
};