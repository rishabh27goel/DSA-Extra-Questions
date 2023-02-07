#include <iostream>
using namespace std;

// Method : Storing character count
// Time Complexity : O(n)  Space Complexity : O(26)
string smallestWindow(string &first, string &second){

    int n1 = first.size();
    int n2 = second.size();


    int charCount1[26] = {0};
    int charCount2[26] = {0};

    for(int i=0; i<second.size(); i++){

        charCount2[second[i]-'a']++;
    }


    int start = 0;
    int end = 0;

    int minLen = INT_MAX;
    int startIndex = -1;

    int c = 0;

    while(end < n1){

        // Add elements in the window
        while(end < n1 && c < n2){

            if(charCount2[first[end]-'a'] != 0 && ++charCount1[first[end]-'a'] <= charCount2[first[end]-'a']){

                c++;
            }

            end++;
        }

        if(end == n1 && c < n2)
            break;

        // Add elements in the window
        while(start < end && c == n2){

            if(end-start < minLen){

                minLen = end-start;
                startIndex = start;
            }

            if(charCount2[first[start]-'a'] != 0 && --charCount1[first[start]-'a'] < charCount2[first[start]-'a']){

                c--;
            }

            start++;
        }
    }

    if(startIndex == -1)
        return "";


    return first.substr(startIndex, minLen);
}

int main()
{
    cout << "Enter first string : ";
    string first;
    cin >> first;

    cout << "Enter second string : ";
    string second;
    cin >> second;


    string window = smallestWindow(first, second);

    cout << "Smallest Window is : " << window;


    cout << endl;
    return 0;
}