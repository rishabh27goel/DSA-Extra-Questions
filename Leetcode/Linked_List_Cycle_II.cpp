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

void insertNode(ListNode* &head, ListNode* &tail, int data){

    ListNode* newNode = new ListNode(data);

    if(head == NULL){

        head = newNode;
    }
    else{

        tail->next = newNode;
    }

    tail = newNode;
}

// Method : Floyd's Cycle Detection
// Time Complexity : O(n)  Space Complexity : O(1)
ListNode* linkedListCycle(ListNode* head){

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){

            fast = head;

            while(slow != fast){

                slow = slow->next;
                fast = fast->next;
            } 

            return slow;
        }
    }

    return NULL;
}

int main()
{
    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter Linked List : ";
    int data = 0;

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        insertNode(head, tail, data);
    }

    tail->next = head->next->next;

    // Linked List Cycle
    ListNode* start = linkedListCycle(head);

    cout << "Starting Node is : " << start->data;

    cout << endl;
    return 0;
}