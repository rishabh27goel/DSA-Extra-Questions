#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Sorting the array
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
// pair<int, int> findKthMaxiMini(vector<int> &arr, int k){

//     int n = arr.size();

//     // Sort the array
//     sort(arr.begin(), arr.end());


//     return make_pair(arr[n-k], arr[k-1]);
// }

// Method 2 : Using Priority Queue
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
// pair<int, int> findKthMaxiMini(vector<int> &arr, int k){

//     int n = arr.size();

//     // Maximum Element
//     priority_queue<int> maxHeap;

//     for(int i=0; i<n; i++){

//         maxHeap.push(arr[i]);
//     }

//     // Minimum Element
//     priority_queue<int, vector<int>, greater<int> > minHeap;

//     for(int i=0; i<n; i++){

//         minHeap.push(arr[i]);
//     }


//     int size = k;

//     while(--size){

//         maxHeap.pop();
//     }

//     size = k;

//     while(--size){

//         minHeap.pop();
//     }

//     return make_pair(maxHeap.top(), minHeap.top());
// }

// Method 3 : Using Priority Queue [Space Reduced]
// Time Complexity : O(n * log(k))  Space Complexity : O(k)
pair<int, int> findKthMaxiMini(vector<int> &arr, int k){

    int n = arr.size();

    // Maximum Element
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int i=0; i<n; i++){

        if(minHeap.size() < k){

            minHeap.push(arr[i]);
        }
        else{

            if(minHeap.top() < arr[i]){

                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }
    }


    // Minimum Element
    priority_queue<int> maxHeap;

    for(int i=0; i<n; i++){

        if(maxHeap.size() < k){

            maxHeap.push(arr[i]);
        }
        else{

            if(maxHeap.top() > arr[i]){

                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
    }

    return make_pair(minHeap.top(), maxHeap.top());
}

int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;

    cout << "Enter array : ";
    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    cout << "Enter k : ";
    int k;
    cin >> k;

    // Find kth maximum & minimum element
    pair<int, int> elements = findKthMaxiMini(arr, k);

    cout << "Maximum Element : " << elements.first << endl;
    cout << "Minimum Element : " << elements.second;


    cout << endl;
    return 0;
}