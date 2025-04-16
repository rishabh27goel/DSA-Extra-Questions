#include <vector>
#include <iostream>
using namespace std;

class FenwickTree {
  public:
    vector<int> treeArray;
    int size;

    FenwickTree(int size) {
        this->size = size + 1;
        this->treeArray.resize(size + 1, 0);
    }

    void update(int position, int updateValue) {
        while(position < size) {
            treeArray[position] += updateValue;
            position += (position & -position);
        }
    }

    // Number of elements (Only to track left count) 
    int query(int position) {
        int totalCount = 0;
        while(position > 0) {
            totalCount += treeArray[position];
            position -= (position & -position);
        }
        return totalCount;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int size = nums1.size();

        vector<int> idxMapping(size);
        for(int idx = 0; idx < size; idx++) {
            idxMapping[nums1[idx]] = idx;
        }

        vector<int> valueToIdxMap(size);
        for(int idx = 0; idx < size; idx++) {
            valueToIdxMap[idxMapping[nums2[idx]]] = idx;
        }

        // Create the Fenwick Tree (To count the number of smaller elements)
        long long goodTriplets = 0;
        FenwickTree tree(size);
    
        for(int value = 0; value < size; value++) {
            int mappedIdx = valueToIdxMap[value];
            
            // Get the count of smaller values on left side using Fenwick tree
            long long leftCount = tree.query(mappedIdx + 1);

            // Values remaining to the right side
            long long rightCount = (size - 1 - mappedIdx);
            rightCount -= (value - leftCount);  // Count of values which are smaller on the right side

            goodTriplets += (leftCount * rightCount);
            tree.update(mappedIdx + 1, 1);
        }

        return goodTriplets;
    }
};