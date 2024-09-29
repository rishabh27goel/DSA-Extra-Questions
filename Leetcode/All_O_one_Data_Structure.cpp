#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

class AllOne {
public:
    unordered_map<string, int> keysFreq;
    map<int, unordered_set<string>> freqToKeys;

    AllOne() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    void inc(string key) {
        auto itr = keysFreq.find(key);
        if(itr == keysFreq.end()) {
            keysFreq[key] = 1;
            freqToKeys[1].insert(key);
        }
        else { 
            int freq = itr->second;
            freqToKeys[freq].erase(key);

            if(freqToKeys[freq].empty())
                freqToKeys.erase(freq);

            keysFreq[key] = freq + 1;
            freqToKeys[freq + 1].insert(key);
        }
    }
    
    void dec(string key) {
        auto itr = keysFreq.find(key);
        int freq = itr->second;

        freqToKeys[freq].erase(key);
        if(freqToKeys[freq].empty())
            freqToKeys.erase(freq);

        if(freq == 1) {
            keysFreq.erase(key);
        }
        else {
            keysFreq[key]--;
            freqToKeys[freq - 1].insert(key);
        }
    }
    
    string getMaxKey() {
        if(freqToKeys.empty())
            return "";

        return *(*freqToKeys.rbegin()).second.begin();
    }
    
    string getMinKey() {
        if(freqToKeys.empty())
            return "";

        return *(*freqToKeys.begin()).second.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */