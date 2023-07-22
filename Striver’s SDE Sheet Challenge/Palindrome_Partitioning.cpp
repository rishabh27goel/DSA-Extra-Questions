#include <iostream>
using namespace std;

// Time : O(n ^ 2 * 2 ^ n)  Space : O(n)
bool isPalindrome(int i, int j, string &str){

    if(i > j)
        return false;

    while(i <= j){

        if(str[i] != str[j])
            return false;

        i++;
        j--;
    }

    return true;
}

void findPartition(int n, string &str, vector<string> &sub, int start, vector<vector<string>> &result){

    // Base Case
    if (start >= n) {
    
        result.push_back(sub);

        return;
    }

    string subStr = "";

    for(int i=start; i<n; i++){

        subStr += str[i];

        if(isPalindrome(start, i, str) == true){

            sub.push_back(subStr);

            findPartition(n, str, sub, i+1, result);

            sub.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    int n = s.size();

    vector<vector<string>> result;
    vector<string> sub;

    findPartition(n, s, sub, 0, result);

    return result;
}