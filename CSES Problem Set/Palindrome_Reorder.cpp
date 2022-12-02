#include <iostream>
using namespace std;

int main()
{
    string input;
    cin >> input;

    int count[26] = {0};

    for(int i=0; i<input.size(); i++){

        count[input[i]-'A']++;
    }


    bool valid = true;
    bool odd = false;

    for(int i=0; i<26; i++){

        if(count[i] % 2 == 0){

            continue;
        }
        else{

            if(odd){

                valid = false;
                break;
            }

            odd = true;
        }
    }

    if(valid){

        string output = "";
        char odd = '.';

        for(int i=0; i<26; i++){

            if(count[i] == 0) 
                continue;

            if(count[i] % 2 == 1){

                odd = (char) (i + 'A');
            }
            else{

                for(int j=1; j<=(count[i]/2); j++){

                    output += (char) (i + 'A');
                }

                count[i] /= 2;
            }
        }

        if(odd != '.'){

            int x = count[odd-'A'];

            while(x--){

                output += odd;
                count[odd-'A']--;
            }
        }
        
        for(int i=25; i>=0; i--){

            if(count[i] == 0) 
                continue;

            for(int j=1; j<=count[i]; j++){

                output += (char) (i + 'A');
            }
        }

        cout << output << endl;
    }
    else{

        cout << "NO SOLUTION" << endl;
    }

    cout << endl;
    return 0;
}