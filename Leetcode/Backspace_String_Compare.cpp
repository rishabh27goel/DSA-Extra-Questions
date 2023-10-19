#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // bool backspaceCompare(string s, string t) {

    //     string a = "";
    //     string b = "";

    //     for(int i=0; i<s.size(); i++){

    //         if(s[i] == '#'){

    //             if(!a.empty())
    //                 a.pop_back();
    //         }
    //         else {

    //             a.push_back(s[i]);
    //         }
    //     }

    //     for(int i=0; i<t.size(); i++){

    //         if(t[i] == '#'){

    //             if(!b.empty())
    //                 b.pop_back();
    //         }
    //         else {

    //             b.push_back(t[i]);
    //         }
    //     }

    //     if(a.size() != b.size())
    //         return false;


    //     for(int i=0; i<a.size(); i++){

    //         if(a[i] != b[i])
    //             return false;
    //     }

    //     return true;
    // }

    bool backspaceCompare(string s, string t) {

        int n1 = s.size();
        int n2 = t.size();

        int i = n1-1;
        int j = n2-1;

        int back1 = 0;
        int back2 = 0;

        while(i >= 0 || j >= 0){

            // Reach the char which can be compared
            while(i >= 0){

                if(s[i] == '#'){

                    back1++;
                    i--;
                }
                else if(back1 > 0){

                    back1--;
                    i--;
                }
                else
                    break;
            }

            while(j >= 0){

                if(t[j] == '#'){

                    back2++;
                    j--;
                }
                else if(back2 > 0){

                    back2--;
                    j--;
                }
                else
                    break;
            }

            if(i >= 0 && j >= 0){

                if(s[i] != t[j])
                    return false;
                
                i--;
                j--;
            }
            else if((i < 0 && j >= 0) || (i >= 0 && j < 0))
                return false;
        }

        return true;
    }
    
};