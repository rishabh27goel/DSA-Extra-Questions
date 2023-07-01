#include <iostream>
#include <vector>
using namespace std;

// Sliding Window
// Time : O(n)  Space : O(1)
int uniqueSubstrings(string input)
{
    int n = input.size();

    int charCount[26] = {0};

    int maxLength = 0;
    int start = 0;
    int end = 0;

    while (end < n) {
    
        charCount[input[end]-'a']++;

        while (start <= end && charCount[input[end] - 'a'] > 1) {
        
            charCount[input[start] - 'a']--;
            start++;
        }

        maxLength = max(end - start + 1, maxLength);
        end++;
    }

    return maxLength;
}

int main()
{
    cout << "Enter input string : ";
    string input;
    cin >> input;


    int maxLen = uniqueSubstrings(input);

    cout << "Longest Substring : " << maxLen;


    cout << endl;
    return 0;
}