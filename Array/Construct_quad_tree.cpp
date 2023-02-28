#include <iostream>
#include <vector>
using namespace std;

class TreeNode {

    public: 
        bool val;
        bool isLeaf;
        TreeNode* topLeft;
        TreeNode* topRight;
        TreeNode* bottomLeft;
        TreeNode* bootomRight;

    TreeNode(bool val){

        this->val = val;
        this->isLeaf = true;
        this->topLeft = NULL;
        this->topRight = NULL;
        this->bottomLeft = NULL;
        this->bootomRight = NULL;
    }
};

TreeNode* createTree(int n, vector< vector<int> > &grid, int rowStart, int colStart, int rowEnd, int colEnd){

    // Base Case
    if(rowStart > rowEnd || colStart > colEnd)
        return NULL;

    TreeNode* node = new TreeNode(0);

    bool isLeaf = true;
    int val = grid[rowStart][colStart];

    for(int i=rowStart; i<=rowEnd; i++){

        for(int j=colStart; j<=colEnd; j++){

            if(grid[i][j] != val){

                isLeaf = false;
                break;
            }
        }
    }

    // Current grid is a leaf node
    if(isLeaf)
        return new TreeNode(val);


    int rowMid = (rowStart + rowEnd) / 2;
    int colMid = (colStart + colEnd) / 2;

    node->topLeft = createTree(n, grid, rowStart, colStart, rowMid, colMid);
    node->topRight = createTree(n, grid, rowStart, colMid+1, rowMid, colEnd);
    node->bottomLeft = createTree(n, grid, rowMid+1, colStart, rowEnd, colMid);
    node->bootomRight = createTree(n, grid, rowMid+1, colMid+1, rowEnd, colEnd);

    node->isLeaf = isLeaf;
    node->val = 1;

    return node;
}

TreeNode* constructQuadTree(vector< vector<int> > &grid){

    int n = grid.size();

    return createTree(n, grid, 0, 0, n-1, n-1);
}

void printTree(TreeNode* root){

    if(root == NULL)
        return;

    cout << "Leaf : " << root->isLeaf << endl;
    cout << "Value : " << root->val << endl;
    cout << endl;

    printTree(root->topLeft);
    printTree(root->topRight);
    printTree(root->bottomLeft);
    printTree(root->bootomRight);
}

int main()
{
    cout << "Enter grid size : ";
    int n;
    cin >> n;

    vector< vector<int> > grid(n, vector<int> (n));

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            cin >> grid[i][j];
        }
    }

    TreeNode* node = constructQuadTree(grid);

    cout << "Printing Tree : " << endl;
    printTree(node);


    cout << endl;
    return 0;
}