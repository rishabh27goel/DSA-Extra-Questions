#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long n;
    cin >> n;

    long long sum = ((n * (n + 1)) >> 1);

    // Odd
    if(sum & 1){

        cout << "NO";
    }
    else{

        vector<long> set1;
        vector<long> set2;
    
        cout << "YES" << endl;

        bool toggle = true;
        long x = 1;

        if(n % 2 == 1){

            x = 4;
    
            set1.push_back(1);
            set1.push_back(2);

            set2.push_back(3);
        }

        while(x <= n){

            if(toggle){

                set1.push_back(x++);
                set2.push_back(x++);
            }
            else{

                set2.push_back(x++);
                set1.push_back(x++);
            }
            
            toggle = !toggle;
        }

        cout << set1.size() << endl;

        for(long i=0; i< (long) set1.size(); i++){

            cout << set1[i] << " ";
        }

        cout << endl;
        cout << set2.size() << endl;

        for(long i=0; i< (long) set2.size(); i++){

            cout << set2[i] << " ";
        }
    }


    return 0;
}