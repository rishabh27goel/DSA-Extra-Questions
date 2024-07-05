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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> result(2, -1);
        
        int minDist = INT_MAX;
        int maxDist = INT_MIN;

        int first = -1;
        int last = -1;

        int distance = 1;
        ListNode* itr = head;
        ListNode* prevNode = NULL;

        while(itr->next != NULL){

            if(prevNode != NULL){
                if((itr->val > itr->next->val && prevNode->val < itr->val) || (itr->val < itr->next->val && prevNode->val > itr->val)){
                    if(first == -1) {
                        first = distance;
                    }
                    else {
                        if(last == -1){
                            last = distance;
                            minDist = min(last - first, minDist);
                        }
                        else {
                            minDist = min(distance - last, minDist);
                            last = distance;
                        }
                    }
                }
            }

            prevNode = itr;
            itr = itr->next;
            distance++;
        }

        if(last != -1){
            maxDist = max(last - first, maxDist);
        }

        if(minDist == INT_MAX || maxDist == INT_MIN)
            return {-1, -1};

        return {minDist, maxDist};
    }
};