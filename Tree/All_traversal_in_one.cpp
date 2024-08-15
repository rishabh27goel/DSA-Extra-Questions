#include <iostream>
#include <vector>
#include <stack>
#include <utility>
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

vector<int> inorder;
vector<int> preorder;
vector<int> postorder;

void findAllTraversal(TreeNode* root) {

    stack < pair<TreeNode*, int> > nodes;
    nodes.push(make_pair(root, 1));

    while(!nodes.empty()) {
        pair <TreeNode*, int> topPr = nodes.top();
        nodes.pop();

        // Value needs to go to preorder
        if(topPr.second == 1) {
            preorder.push_back(topPr.first->data);
            topPr.second++;

            nodes.push(topPr);
            if(topPr.first->left != NULL)
                nodes.push(make_pair(topPr.first->left, 1));
        }
        else if(topPr.second == 2) {
            inorder.push_back(topPr.first->data);
            topPr.second++;

            nodes.push(topPr);
            if(topPr.first->right != NULL)
                nodes.push(make_pair(topPr.first->right, 1));
        }
        else {
            postorder.push_back(topPr.first->data);
        }
    }
}

int main()
{
    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter tree : ";

    TreeNode* root = createTree();    
    findAllTraversal(root);

    cout << "\nPrinting Inorder : ";
    for(int i = 0; i < inorder.size(); i++){
        cout << inorder[i] << " ";
    }

    cout << "\nPrinting Preorder : ";
    for(int i = 0; i < preorder.size(); i++){
        cout << preorder[i] << " ";
    }

    cout << "\nPrinting Postorder : ";
    for(int i = 0; i < postorder.size(); i++){
        cout << postorder[i] << " ";
    }

    return 0;
}