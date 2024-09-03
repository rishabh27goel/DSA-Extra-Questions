#include <iostream>
using namespace std;

int findMaxLength(string &input) {
    int n = input.size();

    int maxLen = 0;
    int j = 0;

    while(j < n) {
        char ch = input[j];
        int c = 0;

        while(j < n && input[j] == ch)
            j++, c++;
    
        maxLen = max(c, maxLen);
    }

    return maxLen;
}

int main()
{
    string input;
    cin >> input;

    int maxLen = findMaxLength(input);
    cout << maxLen;

    return 0;
}