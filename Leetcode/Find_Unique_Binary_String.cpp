#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    string findDifferentBinaryString(vector<string>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();

        string result = "";

        for(int i=0; i<n; i++){

            result.push_back((nums[i][i] == '0') ? '1' : '0');
        }

        return result;
    }

    // int findNumber(string &number){

    //     int result = 0;
    //     int num = 1;

    //     int j = number.size()-1;

    //     while(j >= 0){

    //         if(number[j] == '1')
    //             result += num;

    //         num <<= 1;
    //         j--;
    //     }

    //     return result;
    // }

    // string getString(int num, int n){

    //     string result = "";
    //     int val = 1;

    //     for(int j=0; j<n; j++){

    //         result.push_back((num & val) ? '1' : '0');
    //         val <<= 1;
    //     }

    //     reverse(result.begin(), result.end());
    //     return result;
    // }

    // string findDifferentBinaryString(vector<string>& nums) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = nums.size();

    //     vector<bool> exists(n + 1, false);
    
    //     for(int i=0; i<n; i++){

    //         int val = findNumber(nums[i]);

    //         if(val < n)
    //             exists[val] = true;
    //     }


    //     for(int i=0; i<=n; i++){

    //         cout << exists[i] << " ";

    //         if(exists[i] == false){

    //             return getString(i, n);
    //         }
    //     }

    //     return "";
    // }
};