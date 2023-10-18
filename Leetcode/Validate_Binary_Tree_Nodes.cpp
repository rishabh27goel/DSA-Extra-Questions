#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // int findRootNode(int n, vector<int> &leftChild, vector<int> &rightChild){

    //     // There should be only one root at the end

    //     unordered_set<int> st;

    //     for(int i=0; i<n; i++){

    //         st.insert(i);
    //     }

    //     for(int i=0; i<n; i++){

    //         st.erase(leftChild[i]);
    //         st.erase(rightChild[i]);
    //     }

    //     // Only single root is present
    //     if(st.size() == 1)
    //         return *(st.begin());

    //     return -1;
    // }

    // bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int root = findRootNode(n, leftChild, rightChild);

    //     if(root == -1)
    //         return false;

    //     queue<int> q;
    //     unordered_set<int> visited;

    //     q.push(root);

    //     while(!q.empty()){

    //         int size = q.size();

    //         while(size--){

    //             int front = q.front();
    //             q.pop();

    //             if(visited.find(front) != visited.end())
    //                 return false;

    //             visited.insert(front);

    //             if(leftChild[front] != -1)
    //                 q.push(leftChild[front]);

    //             if(rightChild[front] != -1)
    //                 q.push(rightChild[front]);
    //         }
    //     }

    //     return visited.size() == n;
    // }

    int findParent(int node, vector<int> &parent){

        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> parent;

        for(int i=0; i<n; i++){

            parent.push_back(i);
        }


        int component = n;

        for(int i=0; i<n; i++){

            if(leftChild[i] != -1){

                int p1 = findParent(i, parent);
                int p2 = findParent(leftChild[i], parent);

                if(p1 == p2 || p2 != leftChild[i])
                    return false;

                parent[p2] = p1;
                component--;
            }

            if(rightChild[i] != -1){

                int p1 = findParent(i, parent);
                int p2 = findParent(rightChild[i], parent);

                if(p1 == p2 || p2 != rightChild[i])
                    return false;

                parent[p2] = p1;
                component--;
            }
        }

        return component == 1;
    }
};