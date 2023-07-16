#include <iostream>
#include <unordered_map>
using namespace std;


template <typename T>   
class LinkedListNode
{
    public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;

    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*> mp;

    LinkedListNode<int> *newHead = NULL;
    LinkedListNode<int> *newTail = NULL;
    
    LinkedListNode<int> *itr = head;

    while(itr != NULL){

        LinkedListNode<int> *newNode = new LinkedListNode<int>(itr->data);

        mp[itr] = newNode;

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

        LinkedListNode<int> *node = mp[itr->random];        

        mp[itr]->random = node;
        itr = itr->next;
    }

    return newHead;
}
