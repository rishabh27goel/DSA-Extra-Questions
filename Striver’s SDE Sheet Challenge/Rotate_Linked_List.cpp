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
// Time : O(n)  Space : O(1)
Node *rotate(Node *head, int k) {
     
    int n = 1;

    Node* itr = head;

    while (itr->next != NULL) {
    
        n++;
        itr = itr->next;
    }

    k = (k % n);
    k = n - k;

    itr->next = head;

    Node* prev = NULL;
    itr = head;

    while (k--) {
    
        prev = itr;
        itr = itr->next;
    }

    prev->next = NULL;

    return itr;
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

    cout << "Enter k : ";
    int k;
    cin >> k;


    Node* itr = rotate(head, k);

    cout << "Updated List : ";

    while (itr != NULL) {

        cout << itr->data << " ";

        itr = itr->next;
    }
    



    cout << endl;
    return 0;
}