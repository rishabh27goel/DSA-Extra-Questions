#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Method 1 : Using Depth First Search
// Time Complexity : O(k ^ n)  [k is variable for recursive calls]
// Space Complexity : O(n)
// int findJumps(int n, vector<int> &arr, vector<bool> &visited, unordered_map< int, vector<int> > &mp, int index){

//     // Base Case & if already exists in the path
//     if(index >= n || index < 0 || visited[index])
//         return INT_MAX;

//     // Valid Case
//     if(index == n-1)
//         return 0;

//     visited[index] = true;

//     int first = findJumps(n, arr, visited, mp, index + 1);
//     int second = findJumps(n, arr, visited, mp, index - 1);    
//     int third = INT_MAX;

//     if(mp.find(arr[index]) != mp.end()){

//         for(int nextIndex : mp[arr[index]]){

//             int val = findJumps(n, arr, visited, mp, nextIndex);

//             third = min(val, third);
//         }
//     }

//     // Backtracking
//     visited[index] = false;

//     int result = min(first, min(second, third));

//     return result == INT_MAX ? result : result+1;
// }

// int findMinJumps(vector<int> &arr){

//     int n = arr.size();

//     unordered_map< int, vector<int> > mp;
//     vector<bool> visited(n);

//     for(int i=0; i<n; i++){

//         visited[i] = false;
//         mp[arr[i]].push_back(i);
//     }

//     return findJumps(n, arr, visited, mp, 0);
// }

// Method 2 : Using Breadth First Search
// Time Complexity : O(k ^ n)  [k is variable for recursive calls]
// Space Complexity : O(n)
int findMinJumps(vector<int> &arr){

    int n = arr.size();

    unordered_map< int, vector<int> > mp;
    vector<bool> visited(n);

    for(int i=0; i<n; i++){

        visited[i] = false;
        mp[arr[i]].push_back(i);
    }

    int steps = 0;
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while(!q.empty()){

        int size = q.size();

        while(size--){

            int front = q.front();
            q.pop();

            if(front == n-1)
                return steps;

            // Map of equal values
            vector<int> &traverseIndex = mp[arr[front]];

            // Previous Index
            traverseIndex.push_back(front - 1);

            // Next Index
            traverseIndex.push_back(front + 1);
        

            for(int nextIndex : traverseIndex){

                if(nextIndex >= 0 && nextIndex < n && visited[nextIndex] == false){

                    visited[nextIndex] = true;
                    q.push(nextIndex);
                }
            }

            // As we have traversed indexes and pushed them in queue
            // No need of them in further passes
            traverseIndex.clear();
        }

        steps++;
    }

    return -1;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    // Minimum Jumps
    int minJump = findMinJumps(arr);

    cout << "Minimum Jumps : " << minJump;


    cout << endl;
    return 0;
}