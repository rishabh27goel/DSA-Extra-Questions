#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = people.size();

        // Sort the array
        sort(people.begin(), people.end());
    
        int result = 0;
        int i = 0;
        int j = n-1;

        while(i <= j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
            }
            else {
                j--;
            }
            result++;
        }
        
        return result;
    }
};