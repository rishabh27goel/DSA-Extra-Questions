using namespace std;
#include <vector>
#include <iostream>
#include <list>


// class MyHashMap {
// public:

//     int hash[1000001];

//     MyHashMap() {
        
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);

//         memset(hash, -1, sizeof(hash));
//     }
    
//     void put(int key, int value) {
//         hash[key] = value;
//     }
    
//     int get(int key) {
//         return hash[key];
//     }
    
//     void remove(int key) {
//         hash[key] = -1;
//     }
// };

class MyHashMap {
public:

    vector<list<pair<int, int>>> hashMap;
    int maxSize = 10000;

    MyHashMap() {
        
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        cout.tie(NULL);

        hashMap.resize(maxSize);
    }
    
    void put(int key, int value) {
        
        int hash = (key % maxSize);

        for(auto &pr : hashMap[hash]){

            if(pr.first == key){

                pr.second = value;
                return;
            }
        }
    
        hashMap[hash].push_back(make_pair(key, value));
    }
    
    int get(int key) {

        int hash = (key % maxSize);

        for(auto pr : hashMap[hash]){

            if(pr.first == key)
                return pr.second;
        }

        return -1;
    }
    
    void remove(int key) {
        
        int hash = (key % maxSize);
        auto &lst = hashMap[hash];

        for(auto itr = lst.begin(); itr != lst.end(); itr++){

            if(itr->first == key){

                lst.erase(itr);
                return;
            }
        }
    }
};

