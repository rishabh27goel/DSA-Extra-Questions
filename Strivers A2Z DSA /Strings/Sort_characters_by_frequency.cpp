#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string sortByFrequency(string &str){

    int n = str.size();

    int charCount[26] = {0};

    for(int i=0; i<n; i++){

        charCount[str[i]-'a']++;
    }

    priority_queue<pair<int, char> > pq;

    for(int i=0; i<26; i++){

        if(charCount[i] != 0)
            pq.push(make_pair(charCount[i], (char) (i + 'a')));
    }


    string result = "";

    while(!pq.empty()){

        pair<int, char> pr = pq.top();
        pq.pop();

        while(pr.first--){

            result += pr.second;
        }
    }

    return result;
}

int main()
{
    cout << "Input String : ";
    string input;
    cin >> input;

    // Sort by frequency
    string str = sortByFrequency(input);

    cout << "Sorted String : " << str;



    cout << endl;
    return 0;
}