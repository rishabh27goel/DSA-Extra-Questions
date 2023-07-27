#include <iostream>
#include <queue>
using namespace std;

template <typename T>

class TreeNode {

    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getTopView(TreeNode<int> *root) {

    if(root == NULL)
      return {};

    int minVal = INT_MAX;
    unordered_map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){

        int size = q.size();

        while (size--) {

            pair<TreeNode<int> *, int> pr = q.front();
            q.pop();

            if (mp.find(pr.second) == mp.end()) {
            
                mp[pr.second] = pr.first->val;
                minVal = min(pr.second, minVal);
            }
            

            if(pr.first->left != NULL)
                q.push(make_pair(pr.first->left, pr.second - 1));

            if(pr.first->right != NULL)
                q.push(make_pair(pr.first->right, pr.second + 1));
        }
    }

    vector<int> result;

    for(int i=minVal; i<(int) minVal + (int) mp.size(); i++){

        result.push_back(mp[i]);
    }

    return result;
}