#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // cout.tie(NULL);

        int n = students.size();

        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
    
        int total = 0;
        for(int i=0; i<n; i++){
            total += abs(seats[i] - students[i]);
        }

        return total;
    }
};