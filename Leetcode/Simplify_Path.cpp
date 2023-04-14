#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// Method : Converting the string into words by a split
// Time Complexity : O(n)  Space Complexity : O(n)
string simplifyPath(string &str){

    vector<string> words;

    stringstream ss(str);
    string word;

    while(getline(ss, word, '/')){

        if(!words.empty() && word == ".."){

            words.pop_back();
        }
        else if(word != "" && word != "." && word != ".."){

            words.push_back(word);
        }
    }

    if(words.empty())
        return "/";

    string result = "";

    for(int i=0; i<words.size(); i++){

        if(words[i].size())
            result += ('/' + words[i]);
    }

    return result;
}

int main()
{
    cout << "Enter Input : ";
    string str;
    cin >> str;

    // Simplify Path
    string path = simplifyPath(str);

    cout << "Path is : " << path;


    cout << endl;
    return 0;
}