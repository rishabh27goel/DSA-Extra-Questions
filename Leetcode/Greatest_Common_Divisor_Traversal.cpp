#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const int MAX = 1e5 + 1;
bool isPrime[MAX];
int spf[MAX];

void generateSieve(int maxSize){
    
    for(int i=0; i<=maxSize; i++){
        isPrime[i] = true;
        spf[i] = i;
    }

    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i < maxSize; i++){

        // If current number is not prime
        if(isPrime[i] == false)
            continue;

        for(int j = i * i; j < maxSize; j += i){
            
            if(isPrime[j])
                spf[j] = i;

            isPrime[j] = false;
        }
    }
}

void findFactorization(int number, unordered_map<int, vector<int>> &reverseFactorMap, int idx){

    unordered_set<int> factors;
    while(number != 1){

        int smallest = spf[number];
        factors.insert(smallest);
        number /= smallest;
    }

    for(auto itr = factors.begin(); itr != factors.end(); itr++){
        reverseFactorMap[*(itr)].push_back(idx);
    }
}

class Solution {
public:

    // void dfs(int start, vector<vector<int>> &adjList, int &total, vector<bool> &visited){

    //     if(visited[start])
    //         return;

    //     visited[start] = true;
    //     total++;

    //     for(int child : adjList[start]){

    //         if(!visited[child]){

    //             dfs(child, adjList, total, visited);
    //         }
    //     }
    // }   

    // bool canTraverseAllPairs(vector<int>& nums) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     // Fill up the sieve and smallest prime factor
    //     generateSieve();

    //     unordered_map<int, vector<int>> factorMap;
    //     for(int i=0; i<n; i++){
    //         factorMap[i] = findFactorization(nums[i]);
    //     }

    //     unordered_map<int, vector<int>> reverseFactorMap;
    //     for(auto itr = factorMap.begin(); itr != factorMap.end(); itr++){

    //         int idx = itr->first;
    //         for(auto factor : itr->second)
    //             reverseFactorMap[factor].push_back(idx);
    //     }

    //     vector<vector<int>> adjList(n);
    //     for(auto itr = reverseFactorMap.begin(); itr != reverseFactorMap.end(); itr++){

    //         vector<int> &neg = itr->second;
    //         if(neg.size() <= 1)
    //             continue;

    //         for(int i=1; i<neg.size(); i++){
    //             adjList[neg[i]].push_back(neg[i-1]);
    //             adjList[neg[i-1]].push_back(neg[i]);
    //         }
    //     }


    //     vector<bool> visited(n, false);
    //     int total = 0;

    //     dfs(0, adjList, total, visited);

    //     return total == n;
    // }

    int findParent(int node, vector<int> &parent){

        if(node == parent[node])
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = nums.size();
        if(n == 1)  
            return true;

        int maxSize = 0;

        for(int i=0; i<n; i++){

            if(nums[i] == 1)
                return false;   

            maxSize = max(nums[i], maxSize);         
        }

        // Fill up the sieve and smallest prime factor
        generateSieve(maxSize + 2);

        unordered_map<int, vector<int>> reverseFactorMap;
        for(int i=0; i<n; i++){
            findFactorization(nums[i], reverseFactorMap, i);
        }

        vector<int> parent;
        vector<int> rank;
        int component = n;

        for(int i=0; i<n; i++){
            parent.push_back(i);
            rank.push_back(0);
        }

        for(auto itr = reverseFactorMap.begin(); itr != reverseFactorMap.end(); itr++){

            vector<int> &neg = itr->second;
            if(neg.size() <= 1)
                continue;

            for(int i=1; i<neg.size(); i++){

                int p1 = findParent(neg[i-1], parent);
                int p2 = findParent(neg[i], parent);

                if(p1 != p2){

                    if(rank[p1] == rank[p2])
                    parent[p2] = p1;
                    component--;
                }
            }
        }

        return component == 1;
    }
};