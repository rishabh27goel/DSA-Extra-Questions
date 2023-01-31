#include <iostream>
using namespace std;

// Method : Storing Frequency Count
// Time Complexity : O(n)  Space Complexity : O(1) 
int findSumOfBeauty(string &input){

    int n = input.size();

    // Sum of Beauty
    int sum = 0;

    for(int i=0; i<n; i++){

        int charCount[26] = {0};

        for(int j=i; j<n; j++){

            charCount[input[j]-'a']++;

            int minFreq = INT_MAX;
            int maxFreq = INT_MIN;

            for(int k=0; k<26; k++){

                if(charCount[k] != 0){

                    minFreq = min(charCount[k], minFreq);
                    maxFreq = max(charCount[k], maxFreq);
                } 
            }

            sum += (maxFreq - minFreq);
        }
    }

    return sum;
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    int sum = findSumOfBeauty(input);

    cout << "Sum of Beauty : " << sum;


    cout << endl;
    return 0;
}