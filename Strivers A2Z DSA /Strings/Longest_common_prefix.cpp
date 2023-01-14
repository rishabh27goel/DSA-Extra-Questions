#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &words){

    int n = words.size();

    string prefix = "";
    int j = 0;

    while(j < words[0].size()){

        char ch = words[0][j];

        for(int i=1; i<words.size(); i++){

            if(words[i].size() == j || words[i][j] != ch)
                return prefix;
        }

        prefix += ch;
        j++;
    }

    return prefix;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector<string> words(n);

    for(int i=0; i<n; i++){

        cin >> words[i];
    }

    // Longest Common Prefix
    string prefix = longestCommonPrefix(words);

    cout << "Prefix is : " << prefix;



    cout << endl;
    return 0;
}