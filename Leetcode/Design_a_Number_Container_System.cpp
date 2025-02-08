#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

class NumberContainers {
public:
    unordered_map<int, set<int>> numberToContainerMapping;
    unordered_map<int, int> containerToNumberMapping;

    NumberContainers() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    void change(int index, int number) {
        auto numberItr = containerToNumberMapping.find(index);
        auto &numberSet = numberToContainerMapping[number];
        
        if(numberItr != containerToNumberMapping.end()) {
            numberToContainerMapping[numberItr->second].erase(index);
        }

        containerToNumberMapping[index] = number;
        numberSet.insert(index);
    }
    
    int find(int number) {
        auto &numberSet = numberToContainerMapping[number];
        if(numberSet.empty()) 
            return -1;

        return *(numberSet.begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */