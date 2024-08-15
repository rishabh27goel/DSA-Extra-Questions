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
// void printPreorder(TreeNode* root) {
//     if(root == NULL)    return;

//     cout << root->data << " ";

//     printPreorder(root->left);
//     printPreorder(root->right);
// }

// Method 2 : 
// Time : O(n)  Space : O(n)
void printPreorder(TreeNode* root) {
    if(root == NULL)    return;

    stack<TreeNode*> nodes;
    nodes.push(root);

    while(!nodes.empty()){
        TreeNode* top = nodes.top();
        nodes.pop();

        cout << top->data << " ";

        if(top->right != NULL)
            nodes.push(top->right);

        if(top->left != NULL)
            nodes.push(top->left);
    }
}

int main()
{
    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter tree : ";

    TreeNode* root = createTree();
    printPreorder(root);

    return 0;
}