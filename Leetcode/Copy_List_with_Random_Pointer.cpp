#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        if(head == NULL)
            return NULL;

        unordered_map<Node*, Node*> mapping;

        Node* newHead = NULL;
        Node* newTail = NULL;

        Node* itr = head;

        while(itr != NULL){

            Node* newNode = new Node(itr->val);
            mapping[itr] = newNode;

            if(newHead == NULL){

                newHead = newNode;
            }
            else{

                newTail->next = newNode;
            }

            newTail = newNode;
            itr = itr->next;
        }


        itr = head;

        while(itr != NULL){

            mapping[itr]->random = mapping[itr->random];
            itr = itr->next;
        }

        return newHead;
    }
};