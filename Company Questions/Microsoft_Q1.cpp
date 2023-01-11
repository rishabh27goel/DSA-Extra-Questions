// You are given an array S consisting of N strings. Every string is of the same length M. 
// Your task is to find a pair of strings in array S, such that there exists a position in 
// which both of the strings have the same letter. 
// Both the index in array S and the positions in the strings are numbered from zero. 

// For example, given S = ["abc", "bca", "dbe"], string 0 ("abc") and string 2 ("dbe") 
// have the same letter 'b' in position 1. 
// On the other hand, for strings "abc" and "bca" there does not exist a position in 
// which they have the same letter.

// Write a function that, given a zero-indexed array S of N strings, returns an array describing
// a pair of strings from S which share a common letter at some index. If there is no such pair, the function should return an empty array. If there is more than one correct answer, the function can return any of them.
// The result should be represented as an array containing three integers. The first two integers are the indexes in S of the strings belonging to the pair. The third integer is the position of the common letter.
// For S = ["abc", "bca", "dbe"], as above, the result array should be represented as [0, 2, 1]. Another correct answer is [2, 0, 1], as the order of indexes of strings does not matter.

#include <iostream>
#include <vector>
using namespace std;

vector<int> findPairs(vector<string> &words){

    int n = words.size();
    int m = words[0].size();

    vector<int> result;
    vector< vector<int> > charCount(m, vector<int> (26, -1));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            if(charCount[j][words[i][j]-'a'] == -1){

                charCount[j][words[i][j]-'a'] = i;
            }
            else{

                result.push_back(charCount[j][words[i][j]-'a']);
                result.push_back(i);
                result.push_back(j);
                
                return result;
            }
        }
    }

    return result;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    cout << "Enter strings : ";
    vector <string> words;

    for(int i=0; i<n; i++){

        string str;
        cin >> str;

        words.push_back(str);
    }

    vector<int> result = findPairs(words);

    cout << "Result is : ";

    for(int i=0; i<result.size(); i++){

        cout << result[i] << " ";
    }


    cout << endl;
    return 0;
}