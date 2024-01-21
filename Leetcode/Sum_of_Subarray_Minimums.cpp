#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    const int m = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = arr.size();

        int left[n];
        int right[n];

        stack<pair<int, int>> st1;
        stack<pair<int, int>> st2;

        for(int i=0; i<n; i++){

            int c = 1;

            while(!st1.empty() && arr[i] < st1.top().first){

                c += st1.top().second;
                st1.pop();
            }

            st1.push(make_pair(arr[i], c));
            left[i] = c;
        }

        for(int i=n-1; i>=0; i--){

            int c = 1;

            while(!st2.empty() && arr[i] <= st2.top().first){

                c += st2.top().second;
                st2.pop();
            }

            st2.push(make_pair(arr[i], c));
            right[i] = c;
        }


        long result = 0;

        for(int i=0; i<n; i++){

            result = (result + (left[i] * (long) arr[i] * right[i])) % m;
        }

        return result % m;
    }
};