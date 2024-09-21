#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // vector<int> lexicalOrder(int n) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     vector<int> numbers;
    //     for(int j = 1; j <= n; j++) {
    //         numbers.push_back(j);
    //     }

    //     sort(numbers.begin(), numbers.end(), [&](int x, int y){
    //         string sX = to_string(x);
    //         string sY = to_string(y);

    //         return sX < sY;
    //     });

    //     return numbers;
    // }

    vector<int> lexicalOrder(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> number;
        int counter = 1;

        for(int j = 0; j < n; j++) {
            number.push_back(counter);
            if(counter * 10 <= n) {
                counter *= 10;
            }
            else {
                while(counter % 10 == 9 || counter == n) {
                    counter /= 10;
                }
                counter++;
            }
        }
        
        return number;
    }
};