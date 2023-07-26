#include <iostream>
#include <queue>
using namespace std;

template <typename T> 
class BinaryTreeNode 
{
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> bottomView(BinaryTreeNode<int> * root){

    int minVal = INT_MAX;
    unordered_map<int, int> mp;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){

        int size = q.size();

        while(size--){

            pair<BinaryTreeNode<int> *, int> pr = q.front();
            q.pop();

            mp[pr.second] = pr.first->data;
            minVal = min(pr.second, minVal);

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
