#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    class TrieNode {
        public:
            char data;
            int wc;
            TrieNode* child[26];
            
        TrieNode(char data) {
            this->data = data;
            this->wc = 0;
            for(int j = 0; j < 26; j++)
                child[j] = NULL;
        }
    };
    
    TrieNode* root;
    void addWord(string &word) {
        TrieNode* itr = root;
        int j = 0;

        while(j < word.size()) {
            TrieNode* node = itr->child[word[j]-'a'];
            if(node == NULL) {
                node = new TrieNode(word[j]);
                itr->child[word[j]-'a'] = node;
            }        

            itr = node;
            itr->wc++, j++;
        }
    }

    int findPrefixCount(string &word) {
        TrieNode* itr = root;
        int total = 0;
        int j = 0;

        while(j < word.size()) {
            itr = itr->child[word[j]-'a'];
            total += itr->wc, j++;
        }

        return total;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        root = new TrieNode('/');
        for(int j = 0; j < words.size(); j++) {
            addWord(words[j]);
        }

        vector<int> prefixCounts;
        for(int j = 0; j < words.size(); j++) {
            int total = findPrefixCount(words[j]);
            prefixCounts.push_back(total);
        }
        return prefixCounts;        
    }

    // vector<int> sumPrefixScores(vector<string>& words) {
    //     unordered_map<string, int> prefixMap;
    //     for(int j = 0; j < words.size(); j++) {
    //         string prefix = "";

    //         for(int k = 0; k < words[j].size(); k++) {
    //             prefix.push_back(words[j][k]);
    //             prefixMap[prefix]++;
    //         }
    //     }

    //     vector<int> prefixCounts;
    //     for(int j = 0; j < words.size(); j++) {
    //         int count = 0;
    //         string prefix = "";

    //         for(int k = 0; k < words[j].size(); k++) {
    //             prefix.push_back(words[j][k]);
    //             if(prefixMap.find(prefix) != prefixMap.end())
    //                 count += prefixMap[prefix];                    
    //         }
    //         prefixCounts.push_back(count);
    //     }

    //     return prefixCounts;
    // }
};