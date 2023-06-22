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

// Constant Time
// Time : O(1)  Space : O(1)
void deleteNode(LinkedListNode<int>* node) {
    
    *(node) = *(node->next);
}

int main()
{
    LinkedListNode<int>* head = NULL;
    LinkedListNode<int>* tail = NULL;

    int data = 0;

    cout << "Enter list : ";    

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        LinkedListNode<int>* node = new LinkedListNode<int>(data);

        addNode(head, tail, node);
    }


    deleteNode(head->next->next);


    LinkedListNode<int>* itr = head;

    cout << "New List : ";

    while(itr != NULL){

        cout << itr->data << " ";

        itr = itr->next;
    }
    


    cout << endl;
    return 0;
}