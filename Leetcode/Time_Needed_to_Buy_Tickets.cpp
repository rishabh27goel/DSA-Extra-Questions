#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int timeRequiredToBuy(vector<int>& tickets, int k) {

    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = tickets.size();

    //     queue<pair<int, int>> q;
    //     for(int i=0; i<n; i++){
    //         q.push(make_pair(tickets[i], i));
    //     }

    //     int result = 0;
    //     while(!q.empty()){

    //         pair<int, int> pr = q.front();
    //         q.pop();

    //         pr.first--;
    //         result++;

    //         if(pr.second == k && pr.first == 0)
    //             return result;

    //         if(pr.first > 0)
    //             q.push(pr);
    //     }

    //     return result;
    // }

    int timeRequiredToBuy(vector<int>& tickets, int k) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = tickets.size();

        int result = 0;

        for(int i=0; i<n; i++){
            if(i > k){
                result += min(tickets[i], tickets[k]-1);
            }
            else {
                result += min(tickets[i], tickets[k]);
            }
        }

        return result;
    }
};