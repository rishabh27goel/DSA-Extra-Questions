#include <iostream>
#include <stack>
using namespace std;

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

TreeNode* createTree() {
    int data;
    cin >> data;

    if(data == -1)
        return NULL;

    TreeNode* root = new TreeNode(data);
    root->left = createTree();
    root->right = createTree();

    return root;
}


// Method 1 : 
// Time : O(n)  Space : O(n)
// void printPostorder(TreeNode* root) {
//     if(root == NULL)    return;

//     printPostorder(root->left);
//     printPostorder(root->right);

//     cout << root->data << " ";
// }

// Method 2 : 
// Time : O(n)  Space : O(n)
void printPostorder(TreeNode* root) {
    if(root == NULL)    return;

    stack<TreeNode*> nodes; 
    stack<TreeNode*> store;
    nodes.push(root);

    while(!nodes.empty()){
        TreeNode* top = nodes.top();
        nodes.pop();

        store.push(top);

        if(top->left != NULL)
            nodes.push(top->left);

        if(top->right != NULL)
            nodes.push(top->right);
    }

    while(!store.empty()){
        TreeNode* top = store.top();
        store.pop();

        cout << top->data << " ";
    }
}

int main()
{
    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter tree : ";

    TreeNode* root = createTree();
    printPostorder(root);


    return 0;
}