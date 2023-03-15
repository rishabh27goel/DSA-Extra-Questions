#include <iostream>
#include <queue>
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

TreeNode* createTree(TreeNode* root){

    int data;
    cin >> data;

    if(data == -1)
        return NULL;

    root = new TreeNode(data);

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

// Method 1 : Level order traversal & track of last node
// Time Complexity : O(n)  Space Complexity : O(n)
// bool checkCompleteness(TreeNode* root){

//     // Base Case
//     if(root == NULL)
//         return true;

//     bool flag = false;
//     queue<TreeNode*> q;

//     q.push(root);

//     while(!q.empty()){

//         TreeNode* node = q.front();
//         q.pop();

//         // Left Child
//         if(node->left != NULL){

//             if(flag == true)
//                 return false;

//             q.push(node->left);
//         }
//         else{

//             flag = true;
//         }

//         // Right Child
//         if(node->right != NULL){

//             if(flag == true)
//                 return false;

//             q.push(node->right);
//         }
//         else{

//             flag = true;
//         }
//     }   

//     return true;
// }

// Method 2 : Level order traversal & including NULL as well 
// Time Complexity : O(n)  Space Complexity : O(n)
bool checkCompleteness(TreeNode* root){

    // Base Case
    if(root == NULL)
        return true;


    bool flag = false;
    queue<TreeNode*> q;
    
    q.push(root);

    while(!q.empty()){

        TreeNode* node = q.front();
        q.pop();

        if(node == NULL){

            flag = true;
        }
        else{

            if(flag == true)
                return false;

            q.push(node->left);
            q.push(node->right);
        }
    }   

    return true;
}

int main()
{
    TreeNode* root = NULL;

    cout << "Enter data : ";

    root = createTree(root);

    // Completeness of Binary Tree
    bool check = checkCompleteness(root);

    if(check){

        cout << "Tree is Complete !!";
    }
    else{

        cout << "Tree is not Complete !!";
    }


    cout << endl;
    return 0;
}