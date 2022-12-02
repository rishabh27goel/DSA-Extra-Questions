#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void findPermutaions(string &str, int ind, set<string> &output){

    if(ind == (int)str.size()-1){

        output.insert(str);
        return;
    }

    for(int i=ind; i<(int)str.size(); i++){

        if(str[i] == (int) str[ind] && i != ind)
            continue;

        swap(str[ind], str[i]);

        findPermutaions(str, ind+1, output);

        swap(str[ind], str[i]);
    }
}

int main()
{
    string input;
    cin >> input;

    set<string> output;
    
    findPermutaions(input, 0, output);

    cout << output.size() << endl;

    vector<string> vt(output.begin(), output.end());

    for(int i=0; i<(int)vt.size(); i++){

        cout << vt[i] << endl;
    }

    cout << endl;
    return 0;
}