#include <iostream>
using namespace std;

class ListNode {

    public:
        int data;
        ListNode* next;

    ListNode(int data){

        this->data = data;
        this->next = NULL;
    }
};

void addNode(ListNode* &head, ListNode* &tail, int data){

    ListNode* newNode = new ListNode(data);

    if(head == NULL){

        head = newNode;
    }
    else{

        tail->next = newNode;
    }

    tail = newNode;
}

// Method : Linear Method [Traversal From End] 
// Time Complexity : O(n)  Space Complexity : O(1)
ListNode* reverseList(ListNode* head){

    ListNode* store = NULL;
    ListNode* prev = NULL;

    while(head->next != NULL){

        store = head->next;
        head->next = prev;
        prev = head;
        head = store;
    }

    head->next = prev;
    return head;
}

ListNode* removeNodes(ListNode* head){

    // Reverse List
    head = reverseList(head);

    ListNode* newHead = head;
    ListNode* newTail = head;

    int maxVal = head->data;
    ListNode* itr = head->next;

    while(itr != NULL){

        if(maxVal <= itr->data){

            newTail->next = itr;
            newTail = itr;
            maxVal = itr->data;
        }

        itr = itr->next;
    }

    newTail->next = NULL;

    // Reverse List
    newHead = reverseList(newHead);

    return newHead;
}

int main()
{
    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter Linked List Data : ";
    int data = 0;

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        addNode(head, tail, data);
    }

    // Remove Nodes 
    ListNode* itr = removeNodes(head);

    cout << "Updated List : ";

    while(itr != NULL){

        cout << itr->data << " ";

        itr = itr->next;
    }

    cout << endl;
    return 0;
}