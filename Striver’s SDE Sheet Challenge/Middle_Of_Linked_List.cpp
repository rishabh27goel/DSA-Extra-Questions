#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;

    Node(int data){

        this->data = data; 
        this->next = NULL;
    }
};

void addNode(Node* &head, Node* &tail, Node* &itr){

    if(head == NULL){

        head = itr;
    }
    else{

        tail->next = itr;
    }

    tail = itr;
}

// Linear Method 
// Time : O(n + m)  Space : O(1)
Node* findMiddle(Node* head) {
    
    if(head->next == NULL)
        return head;

    Node* fast = head;
    Node* middle = head;

    while(fast != NULL && fast->next != NULL){

        middle = middle->next;
        fast = fast->next->next;
    }

    return middle;
}

int main()
{
    int data = 0;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter list : ";

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        Node* node = new Node(data);

        addNode(head, tail, node);
    }

    
    Node* middle = findMiddle(head);

    cout << "Middle Node : " << middle->data;


    cout << endl;
    return 0;
}