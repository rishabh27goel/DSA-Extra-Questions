#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        Node *next;

    Node(int data) {

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
// Time : O(max(n, m))  Space : O(1)
Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* head = NULL;
    Node* tail = NULL;

    Node* itr1 = num1;    
    Node* itr2 = num2;

    int carry = 0;

    while(itr1 != NULL || itr2 != NULL){

        int n1 = 0;
        
        if(itr1 != NULL){

            n1 = itr1->data;
            itr1 = itr1->next;
        }
        
        int n2 = 0;

        if(itr2 != NULL){

            n2 = itr2->data;
            itr2 = itr2->next;
        }

        int val = n1 + n2 + carry;

        Node* newNode = new Node(val % 10);
        addNode(head, tail, newNode);

        carry = (val / 10);
    }

    if(carry != 0){

        Node* newNode = new Node(carry);

        addNode(head, tail, newNode);
    }

    return head;
}

int main()
{
    int data = 0;

    Node* firstHead = NULL;
    Node* firstTail = NULL;

    cout << "Enter first list : ";

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        Node* node = new Node(data);

        addNode(firstHead, firstTail, node);
    }

    data = 0;

    Node* secondHead = NULL;
    Node* secondTail = NULL;

    cout << "Enter second list : ";

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        Node* node = new Node(data);

        addNode(secondHead, secondTail, node);
    }


    Node* itr = addTwoNumbers(firstHead, secondHead);

    cout << "New List : ";

    while(itr != NULL){

        cout << itr->data << " ";

        itr = itr->next;
    }

    cout << endl;
    return 0;
}