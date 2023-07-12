#include <iostream>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Node {

    public:
        int data;
        Node* child[26];
        bool isEnd;

    Node(int data){

        this->data;

        for(int i=0; i<26; i++){

            child[i] = NULL;
        }

        this->isEnd = false;
    }
};

class Trie {

public:

    Node* root;

    /** Initialize your data structure here. */
    Trie() {

        root = new Node('\0');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        Node* itr = root;
        int j = 0;

        while(j < word.size()){

            Node* newNode;

            if (itr->child[word[j]-'a'] == NULL) {
            
                newNode = new Node(word[j]);
                itr->child[word[j]-'a'] = newNode;
            } 
            else {
                
                newNode = itr->child[word[j]-'a'];
            }

            itr = newNode;
            j++;
        }

        itr->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        Node* itr = root;
        int j = 0;

        while(j < word.size()){

            Node* newNode;

            if (itr->child[word[j]-'a'] == NULL) {
            
                return false;
            } 
            else {
                
                newNode = itr->child[word[j]-'a'];
            }

            itr = newNode;
            j++;
        }

        return itr->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {

        Node* itr = root;
        int j = 0;

        while(j < word.size()){

            Node* newNode;

            if (itr->child[word[j]-'a'] == NULL) {
            
                return false;
            } 
            else {
                
                newNode = itr->child[word[j]-'a'];
            }

            itr = newNode;
            j++;
        }

        return true;
    }
};