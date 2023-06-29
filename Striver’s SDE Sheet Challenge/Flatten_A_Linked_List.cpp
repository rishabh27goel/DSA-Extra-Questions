#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
    	int data;
 		Node *next;
  		Node *child;

 	Node(int x) : data(x), next(nullptr), child(nullptr) {}
};

class Compare {

	public:
		bool operator()(Node* n1, Node* n2){

			return n1->data > n2->data;
		}
};


Node* flattenLinkedList(Node *head) {

	Node* newHead = NULL;
	Node* newTail = NULL;

	priority_queue<Node *, vector<Node *>, Compare> pq;
	Node *itr = head;

	while (itr != NULL) {

		Node* nextNode = itr->next;
		itr->next = NULL;
		pq.push(itr);

		itr = nextNode;
	}

  	while (!pq.empty()) {
  
		Node* top = pq.top();
		pq.pop();

		if(top->child != NULL){

			pq.push(top->child);
		}

		if(newHead == NULL)
			newHead = top;
		else
			newTail->child = top;

		newTail = top;
  	}

	return newHead;
}
