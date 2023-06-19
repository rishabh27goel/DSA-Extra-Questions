#include <iostream>
using namespace std;

template <typename T>
class LinkedListNode
{
    public:
        T data;
        LinkedListNode<T> *next;

    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void addNode(LinkedListNode<int>* &head, LinkedListNode<int>* &tail, LinkedListNode<int>* &itr){

    if(head == NULL){

        head = itr;
    }
    else{

        tail->next = itr;
    }

    tail = itr;
}


// Linear Method
// Time : O(n)  Space : O(1)
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL || head->next == NULL)
        return head;

    LinkedListNode<int>* store = NULL;
    LinkedListNode<int>* prev = NULL;

    while (head->next != NULL) {

      store = head->next;
      head->next = prev;
      prev = head;
      head = store;
    }

    head->next = prev;
    return head;
}


int main()
{
    int data = 0;

    LinkedListNode<int>* head = NULL;
    LinkedListNode<int>* tail = NULL;

    cout << "Enter list : ";

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        LinkedListNode<int>* node = new LinkedListNode<int>(data);

        addNode(head, tail, node);
    }

    


    LinkedListNode<int>* itr = reverseLinkedList(head);

    cout << "Reversed List : ";

    while(itr != NULL){

        cout << itr->data << " ";
        
        itr = itr->next;
    }


    cout << endl;
    return 0;
}