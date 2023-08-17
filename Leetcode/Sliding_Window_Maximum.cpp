#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// Using Priority Queue
// Time : O(n * log(n))  Space : O(n)
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
//         ios_base::sync_with_stdio(false);
//         // cin.tie(NULL);
//         // cout.tie(NULL);

//         int n = nums.size();

//         vector<int> result;
//         priority_queue<pair<int, int>> pq;

//         for(int i=0; i<k; i++){

//             pq.push(make_pair(nums[i], i));
//         }

//         result.push_back(pq.top().first);
     

//         int start = 0;

//         for(int i=k; i<n; i++){

//             while(!pq.empty() && pq.top().second <= i - k){

//                 pq.pop();
//             }


//             pq.push(make_pair(nums[i], i));
//             result.push_back(pq.top().first);
//         }

//         return result;
//     }

// Using Deque
// Time : O(n * log(n))  Space : O(n)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n = nums.size();

    vector<int> result;
    deque<int> dq;
    
    for(int i=0; i<k; i++){

        while(!dq.empty() && nums[dq.back()] <= nums[i]){

            dq.pop_back();
        }

        dq.push_back(i);
    }

    result.push_back(nums[dq.front()]);


    for(int i=k; i<n; i++){

        // Delete based on previous elements
        while(!dq.empty() && nums[dq.back()] <= nums[i]){

            dq.pop_back();
        }

        // Delete if out of window
        while(!dq.empty() && dq.front() <= i - k){

            dq.pop_front();
        }

        dq.push_back(i);
        result.push_back(nums[dq.front()]);
    }

    return result;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector<int> nums;

    for(int i=0; i<n; i++){

        cin >> nums[i];
    }

    cout << "Enter k : ";
    int k;
    cin >> k;


    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Result is : ";

    for(int i=0; i<result.size(); i++){

        cout << result[i] << " ";
    }


    cout << endl;
    return 0;
}