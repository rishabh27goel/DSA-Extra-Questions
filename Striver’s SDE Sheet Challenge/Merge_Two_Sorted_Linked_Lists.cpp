#include <iostream>
using namespace std;

template <typename T>

class Node {
    public:
    T data;
    Node* next;

    Node(T data) {

        this->next = NULL;
        this->data = data;
    }
};

void addNode(Node<int>* &head, Node<int>* &tail, Node<int>* &itr){

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
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;

    Node<int>* newHead = NULL;
    Node<int>* newTail = NULL;

    Node<int>* itr1 = first;
    Node<int>* itr2 = second;

    while(itr1 != NULL && itr2 != NULL){

        if(itr1->data <= itr2->data){

            addNode(newHead, newTail, itr1);
            itr1 = itr1->next;
        }
        else{

            addNode(newHead, newTail, itr2);
            itr2 = itr2->next;
        }
    }

    while(itr1 != NULL){

        addNode(newHead, newTail, itr1);
        itr1 = itr1->next;    
    }

    while(itr2 != NULL){

        addNode(newHead, newTail, itr2);
        itr2 = itr2->next;    
    }

    return newHead;
}

int main()
{
    int data = 0;

    Node<int>* firstHead = NULL;
    Node<int>* firstTail = NULL;

    cout << "Enter first list : ";

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        Node<int>* node = new Node<int> (data);

        addNode(firstHead, firstTail, node);
    }

    data = 0;

    Node<int>* secondHead = NULL;
    Node<int>* secondTail = NULL;

    cout << "Enter second list : ";

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        Node<int>* node = new Node<int> (data);

        addNode(secondHead, secondTail, node);
    }


    Node<int>* itr = sortTwoLists(firstHead, secondHead);

    cout << "Merged List : ";

    while(itr != NULL){

        cout << itr->data << " ";
        itr = itr->next;
    }


    cout << endl;
    return 0;
}