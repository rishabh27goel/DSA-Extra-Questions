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

// Method : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
ListNode* removeDuplicate(ListNode* head){

    if(head == NULL || head->next == NULL)
        return head;

    ListNode* itr = head;

    while(itr->next != NULL){

        if(itr->data == itr->next->data){

            ListNode* tmp = itr->next;
            itr->next = tmp->next;

            delete tmp;
        }
        else{

            itr = itr->next;
        }
    }

    return head;
}

int main()
{
    int data = 0;
    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter List : ";

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        addNode(head, tail, data);
    }

    // Remove Duplicates from Sorted List
    ListNode* itr = removeDuplicate(head);

    cout << "New Linked List : ";

    while(itr != NULL){

        cout << itr->data << " ";
        itr = itr->next;
    }


    cout << endl;
    return 0;
}