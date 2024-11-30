#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Euler path properties are important for this question
    // vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     unordered_map<int, deque<int>> adjList;
    //     unordered_map<int, int> inDegree;
    //     unordered_map<int, int> outDegree;

    //     for(auto pr : pairs) {
    //         adjList[pr[0]].push_back(pr[1]);
    //         inDegree[pr[1]]++;
    //         outDegree[pr[0]]++;
    //     }

    //     // Finding the start node in the euler path
    //     int startNode = -1;
    //     for(auto keyVal : outDegree) {
    //         if(inDegree[keyVal.first] + 1 == keyVal.second) {
    //             startNode = keyVal.first;
    //             break;    
    //         }
    //     }

    //     // No node was found
    //     if(startNode == -1) {
    //         startNode = pairs[0][0];
    //     }
        
    //     vector<int> nodesOrder;
    //     function<void(int)> visitNode = [&](int startNode) {
    //         while(!adjList[startNode].empty()) {
    //             int nextNode = adjList[startNode].front();
    //             adjList[startNode].pop_front();
    //             visitNode(nextNode);
    //         }
    //         nodesOrder.push_back(startNode);
    //     };
    //     visitNode(startNode);

    //     vector<vector<int>> path;
    //     int m = nodesOrder.size();

    //     for(int j = m-2; j >= 0; j--) {
    //         path.push_back({nodesOrder[j+1], nodesOrder[j]});
    //     }

    //     return path;
    // }

    // vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     unordered_map<int, deque<int>> adjList;
    //     unordered_map<int, int> degree;

    //     for(auto pr : pairs) {
    //         adjList[pr[0]].push_back(pr[1]);
    //         degree[pr[0]]++;
    //         degree[pr[1]]--;
    //     }

    //     // Finding the start node in the euler path
    //     int startNode = -1;
    //     for(auto keyVal : degree) {
    //         if(keyVal.second == 1) {
    //             startNode = keyVal.first;
    //             break;    
    //         }
    //     }

    //     // No node was found
    //     if(startNode == -1) {
    //         startNode = pairs[0][0];
    //     }
        
    //     vector<int> nodesOrder;
    //     function<void(int)> visitNode = [&](int startNode) {
    //         while(!adjList[startNode].empty()) {
    //             int nextNode = adjList[startNode].front();
    //             adjList[startNode].pop_front();
    //             visitNode(nextNode);
    //         }
    //         nodesOrder.push_back(startNode);
    //     };
    //     visitNode(startNode);

    //     vector<vector<int>> path;
    //     int m = nodesOrder.size();

    //     for(int j = m-2; j >= 0; j--) {
    //         path.push_back({nodesOrder[j+1], nodesOrder[j]});
    //     }

    //     return path;
    // }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> degree;

        for(auto &pr : pairs) {
            adjList[pr[0]].push_back(pr[1]);
            degree[pr[0]]++;
            degree[pr[1]]--;
        }

        // Finding the start node in the euler path
        int startNode = pairs[0][0];
        for(auto &keyVal : degree) {
            if(keyVal.second == 1) {
                startNode = keyVal.first;
                break;    
            }
        }

        vector<int> nodesOrder;
        stack<int> nodes;
        nodes.push(startNode);

        while(!nodes.empty()) {
            auto &neighbors = adjList[nodes.top()];
            if(neighbors.empty()) {
                nodesOrder.push_back(nodes.top());
                nodes.pop();
            }
            else {
                int nextNode = neighbors.back();
                neighbors.pop_back();
                nodes.push(nextNode);
            }
        }

        int m = nodesOrder.size();

        vector<vector<int>> path;
        for(int j = m-2; j >= 0; j--) {
            path.push_back({nodesOrder[j+1], nodesOrder[j]});
        }

        return path;
    }
};