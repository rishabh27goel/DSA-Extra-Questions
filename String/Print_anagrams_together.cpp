#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector< vector<string> > findAnagramsGroup(vector<string> &words){

    int n = words.size();

    vector< vector<string> > result;
    unordered_map<string, vector<string> > mp;

    for(int i=0; i<n; i++){

        int charCount[26] = {0};

        for(int j=0; j<words[i].size(); j++){

            charCount[words[i][j]-'a']++;
        }

        string hash = "";

        for(int i=0; i<26; i++){

            hash += to_string(charCount[i]);
            hash += (char) (i + 'a');
        }

        mp[hash].push_back(words[i]);
    }


    unordered_map<string, vector<string> > :: iterator itr;

    for(itr = mp.begin(); itr != mp.end(); itr++){

        result.push_back(itr->second);
    }

    return result;
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


    vector< vector<string> > groups = findAnagramsGroup(words);

    cout << "Anagrams Group : \n";

    for(int i=0; i<groups.size(); i++){

        for(int j=0; j<groups[i].size(); j++){

            cout << groups[i][j] << " ";
        }

        cout << endl;
    }


    cout << endl;
    return 0;
}