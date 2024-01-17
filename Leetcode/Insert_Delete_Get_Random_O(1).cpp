#include <iostream>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:

    unordered_map<int, int> exists;
    vector<int> elements;

    RandomizedSet() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    bool insert(int val) {
        
        if(exists.find(val) != exists.end())
            return false;

        exists[val] = elements.size();
        elements.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        
        if(exists.find(val) == exists.end())
            return false;

        // Swap with index
        int idx = exists[val];
        int last = elements.back();

        elements[idx] = last;
        exists[last] = idx;

        elements.pop_back();
        exists.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % elements.size();
        return elements[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */