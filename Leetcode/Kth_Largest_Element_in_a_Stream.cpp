#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

    KthLargest(int k, vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        for(int i=0; i<nums.size(); i++){
            minHeap.push(nums[i]);

            if(minHeap.size() > k)
                minHeap.pop();
        }

        this->size = k;
    }
    
    int add(int val) {
        minHeap.push(val);

        if(minHeap.size() > size)
            minHeap.pop();

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */