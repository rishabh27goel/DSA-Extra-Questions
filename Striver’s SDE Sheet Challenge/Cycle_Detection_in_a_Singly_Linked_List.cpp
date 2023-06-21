#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        Node* next; 

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

// Floyd's Cycle Detection
// Time : O(n)  Space : O(1)
bool detectCycle(Node *head) {

  Node *fast = head;
  Node *slow = head;

  while (fast != NULL && fast->next != NULL) {
      
      slow = slow->next;
      fast = fast->next->next;

      if(slow == fast)
        return true;
  }
  
  return false;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int data = 0;

    cout << "Enter list : ";    

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        Node* node = new Node(data);

        addNode(head, tail, node);
    }

    tail->next = head->next;


    bool detect = detectCycle(head);

    cout << (detect ? "Cycle" : "No Cycle");


    cout << endl;
    return 0;
}