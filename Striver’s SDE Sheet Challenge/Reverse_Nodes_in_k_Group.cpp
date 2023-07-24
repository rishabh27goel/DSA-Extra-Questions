#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* revList(Node* head){

	Node* store = NULL;
	Node* prev = NULL;

	while(head != NULL && head->next != NULL){

		store = head->next;
		head->next = prev;
		prev = head;
		head = store;
	}

	head->next = prev;
	return head;
}

Node* reverseList(Node* head, int n, int *b, int i){

	// Base Case
	if(head == NULL)
		return NULL;

	if(i >= n)
		return head;

	if(b[i] == 0)
		return reverseList(head, n, b, i+1);
	

	Node* itr = head;
	int c = 1;

	while (c < b[i] && itr->next != NULL) {
		
		c++;
		itr = itr->next;
	}

	Node* newHead;

	if (c == b[i]) {
	
		Node* nextNode = itr->next;
		itr->next = NULL;

		newHead = revList(head);
		head->next = reverseList(nextNode, n, b, i+1);
	}
	else{

		return revList(head);		
	}

    return newHead;
}


Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	
	return reverseList(head, n, b, 0);
}