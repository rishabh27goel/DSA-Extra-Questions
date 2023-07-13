#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        int count;
        int prefixCount;
        Node* child[26];
        bool isEnd;

    Node(int data){

        this->data;
        this->count = 0;
        this->prefixCount = 0;

        for(int i=0; i<26; i++){

            child[i] = NULL;
        }

        this->isEnd = false;
    }
};

class Trie{

    public:
        Node* root;

    Trie(){
    
        root = new Node('\0');
    }

    void insert(string &word){
        
        Node* itr = root;
        int j = 0;

        while(j < word.size()){

            Node* newNode;

            if(itr->child[word[j]-'a'] == NULL){

                newNode = new Node(word[j]);
                itr->child[word[j]-'a'] = newNode;
            }
            else{

                newNode = itr->child[word[j]-'a'];
            }

            itr = newNode;
            itr->prefixCount++;
            j++;
        }

        itr->isEnd = true;
        itr->count++;
    }

    int countWordsEqualTo(string &word){
        
        Node* itr = root;
        int j = 0;

        while(j < word.size()){

            Node* newNode;

            if(itr->child[word[j]-'a'] == NULL){

                return 0;
            }
            else{

                newNode = itr->child[word[j]-'a'];
            }

            itr = newNode;
            j++;
        }

        return itr->count;
    }

    int countWordsStartingWith(string &word){
        
        Node* itr = root;
        int j = 0;

        while(j < word.size()){

            Node* newNode;

            if(itr->child[word[j]-'a'] == NULL){

                return 0;
            }
            else{

                newNode = itr->child[word[j]-'a'];
            }

            itr = newNode;
            j++;
        }

        return itr->prefixCount; 
    }

    void erase(string &word){
        
        Node* itr = root;
        int j = 0;

        while(j < word.size()){

            Node* newNode;

            if(itr->child[word[j]-'a'] == NULL){

                return;
            }
            else{

                newNode = itr->child[word[j]-'a'];
            }

            itr = newNode;
            itr->prefixCount--;
            j++;
        }

        itr->isEnd = false;
        itr->count--;
    }
};
