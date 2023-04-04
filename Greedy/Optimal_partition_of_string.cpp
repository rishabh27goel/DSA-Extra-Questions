#include <iostream>
using namespace std;

// Method : Greedy Approach and Hash Table
// Time Complexity : O(n)  Space Complexity : O(1)
int optimalPartition(string &str){

    int n = str.size();

    int result = 0;
    int i = 0;
    
    while(i < n){

        int charCount[26] = {0};

        while(i < n && charCount[str[i]-'a'] == 0){

            charCount[str[i]-'a']++;
            i++;
        }

        result++;
    }

    return result;
}

int main()
{
    cout << "Enter Input : ";
    string str;
    cin >> str;

    int count = optimalPartition(str);

    cout << "Count is : " << count;


    cout << endl;
    return 0;
}