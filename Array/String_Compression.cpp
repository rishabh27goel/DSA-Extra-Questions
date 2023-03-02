#include <iostream>
#include <vector>
using namespace std;

// Method : Two Pointer
// Time Complexity : O(n)  Space Complexity : O(1)
int stringCompression(vector<char> &chars){

    int n = chars.size();

    int result = 0;
    int i = 0;
    int j = 0;

    while(i < n){

        int count = 0;
        char val = chars[i];

        while(i < n && val == chars[i]){

            count++;
            i++;
        }

        if(count == 1){

            result++;
            chars[j++] = val;
        }
        else{

            string str = to_string(count);

            result++;
            chars[j++] = val;

            for(char ch : str){

                result++;
                chars[j++] = ch;
            }
        }
    }

    return result;
} 

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<char> chars(size);

    for(int i=0; i<size; i++){

        cin >> chars[i];
    }

    // String Compression
    int length = stringCompression(chars);


    cout << "Compressed String : ";

    for(int i=0; i<length; i++){

        cout << chars[i];
    }


    cout << endl;
    return 0;
}