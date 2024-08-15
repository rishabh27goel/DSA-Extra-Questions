#include <iostream>
#include <stack>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

TreeNode* createTree() {
    int data;
    cin >> data;

    if(data == -1)  return NULL;

    TreeNode* root = new TreeNode(data);
    root->left = createTree();
    root->right = createTree();

    return root;
}

// Method 1 : Recursive Method
// Time : O(n)  Space : O(n)
// void printInorder(TreeNode* root) {
//     if(root == NULL)  return;

//     printInorder(root->left);
//     cout << root->data << " ";
//     printInorder(root->right);
// }

// Method 2 : Recursive Method
// Time : O(n)  Space : O(n)
void getLeftNodes(TreeNode* node, stack<TreeNode*> &st) {
    while(node != NULL){
        st.push(node);
        node = node->left;
    }
}

void printInorder(TreeNode* root) {
    if(root == NULL)  return;

    stack<TreeNode*> st;
    getLeftNodes(root, st);

    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();

        cout << node->data << " ";
    
        if(node->right != NULL)
            getLeftNodes(node->right, st);
    }

}

int main() 
{
    TreeNode* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter tree : ";
    root = createTree();

    printInorder(root);

    return 0;
}