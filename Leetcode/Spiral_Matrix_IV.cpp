#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<int>> matrix(n, vector<int> (m, -1));
        ListNode* itr = head;        

        int rowStart = 0;
        int rowEnd = n-1;

        int colStart = 0;
        int colEnd = m-1;

        while(itr != NULL) {
            for(int k = colStart; k <= colEnd && itr != NULL; k++) {
                matrix[rowStart][k] = itr->val;
                itr = itr->next;
            }
            rowStart++;
            
            for(int k = rowStart; k <= rowEnd && itr != NULL; k++) {
                matrix[k][colEnd] = itr->val;
                itr = itr->next;
            }
            colEnd--;

            for(int k = colEnd; k >= colStart && itr != NULL; k--) {
                matrix[rowEnd][k] = itr->val;
                itr = itr->next;
            }
            rowEnd--;

            for(int k = rowEnd; k >= rowStart && itr != NULL; k--) {
                matrix[k][colStart] = itr->val;
                itr = itr->next;
            }
            colStart++;
        }

        return matrix;
    }
};