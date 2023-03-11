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

class TreeNode {

    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int data){

        this->data = data;
        this->left = NULL;
        this->right = NULL;
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

void inorderPrint(TreeNode* root){

    if(root == NULL)
        return;

    inorderPrint(root->left);

    cout << root->data << " ";

    inorderPrint(root->right);
}

// Method 1 : Divide and Conquer
// Time Complexity : O(n * log(n))  Space Complexity : O(Stack Space)
// TreeNode* convertHelper(ListNode* start, ListNode* end){

//     // Base Case
//     if(start == end)
//         return NULL;

//     if(start->next == end)
//         return new TreeNode(start->data);

//     ListNode* middle = start;
//     ListNode* fast = start->next;

//     while(fast != end && fast->next != end){

//         middle = middle->next;
//         fast = fast->next->next;
//     }

//     // Root Node
//     TreeNode* rootNode = new TreeNode(middle->data);

//     // Left Child
//     rootNode->left = convertHelper(start, middle);
    
//     // Right Child
//     rootNode->right = convertHelper(middle->next, end);

//     return rootNode;
// }

// TreeNode* convertToBST(ListNode* head){

//     return convertHelper(head, NULL);
// }

// Method 2 : Using count of nodes and Inorder creation
// Time Complexity : O(n)  Space Complexity : O(Stack Space)
int countNode(ListNode* head){

    int count = 0;

    while(head != NULL){

        count++;
        head = head->next;
    }

    return count;
}

TreeNode* convertHelper(ListNode* &head, int n){

    // Base Case
    if(n <= 0)
        return NULL;

    TreeNode* lC = convertHelper(head, n/2);

    TreeNode* rootNode = new TreeNode(head->data);
    head = head->next;

    TreeNode* rC = convertHelper(head, n-n/2-1);

    rootNode->left = lC;
    rootNode->right = rC;

    return rootNode;
}

TreeNode* convertToBST(ListNode* head){

    int n = countNode(head);

    ListNode* start = head;

    return convertHelper(start, n);
}

int main()
{   
    int data = 0;
    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter Linked List : ";

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        addNode(head, tail, data);
    }

    // Convert Sorted List to Binary Search Tree
    TreeNode* root = convertToBST(head);

    cout << "Tree Created : ";
    inorderPrint(root);

    cout << endl;
    return 0;
}