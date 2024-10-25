#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    class TrieNode {
        public:
            string data;
            unordered_map <string, TrieNode*> child;
            bool isEnd;

        TrieNode(string str) {
            this->data = str;
            this->isEnd = false;
        }
    };

    vector<string> removeSubfolders(vector<string>& folder) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        TrieNode* root = new TrieNode("/");
        for(auto &str : folder) {
            istringstream ss(str);
            string folder;

            TrieNode* currNode = root;
            bool hasParent = false;

            while(getline(ss, folder, '/')) {
                if(folder.empty())
                    continue;

                TrieNode* nextNode = NULL;
                auto itr = currNode->child.find(folder);

                if(itr == currNode->child.end()) {
                    nextNode = new TrieNode(folder);
                    currNode->child[folder] = nextNode;
                }
                else {
                    nextNode = itr->second;
                }

                currNode = nextNode;
            }

            currNode->isEnd = true;
        }

        vector <string> result;
        for(auto &str : folder) {
            istringstream ss(str);
            string folder;

            TrieNode* currNode = root;
            bool subExist = false;

            while(getline(ss, folder, '/')) {
                if(folder.empty())
                    continue;

                if(currNode->isEnd) {
                    subExist = true;
                    break;
                } 

                auto itr = currNode->child.find(folder);
                currNode = itr->second;  
            }

            if(!subExist && currNode->isEnd)
                result.push_back(str);
        }

        return result;
    }
};