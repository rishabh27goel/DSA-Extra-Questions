#include <iostream>
using namespace std; 

template <typename T>
class TreeNode
{
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void findPath(TreeNode<int> *root, int target, bool &found, vector<int> &path){

	if(root == NULL || found == true)
		return;

	if (root->data == target) {
	
		path.push_back(root->data);
		found = true;
		return;
	}

    path.push_back(root->data);

	findPath(root->left, target, found, path);

	if(found == true)
		return;

	findPath(root->right, target, found, path);
	
	if(found == true)
		return;

	path.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int target)
{
	bool found = false;
    vector<int> path;

	findPath(root, target, found, path);

	return path;
}
