#include <iostream>
#include <vector>
using namespace std;

// Method : Using Sliding Window
// Time Complexity : O(n)  Space Complexity : O(1)
// Questions : To find min minutes from left and right sides
// Solution : To find max middle subarray [Reverse Thinking]
int eachCharacter(string &str, int k){

    int n = str.size();

    int charCount[3] = {0};

    for(int i=0; i<n; i++){

        charCount[str[i]-'a']++;
    }

    if(charCount[0] < k || charCount[1] < k || charCount[2] < k)
        return -1;

    int minMinute = INT_MAX;
    int start = 0;
    int window = 0;

    for(int i=0; i<n; i++){

        charCount[str[i]-'a']--;
        window++;

        while(charCount[str[i]-'a'] < k){

            charCount[str[start]-'a']++;
            start++;
            window--;
        }

        minMinute = min(minMinute, n - window);
    }

    return minMinute;
}

int main()
{
    cout << "Enter Input : ";
    string str;
    cin >> str;

    cout << "Enter k : ";
    int k;
    cin >> k;

    // Take K of Each Character From Left and Right
    int length = eachCharacter(str, k);

    cout << "Minimum Minutes : " << length;


    cout << endl;
    return 0;
}