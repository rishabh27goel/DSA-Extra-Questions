#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int factors[1000001] = {0};

    for(int i=0; i<n; i++){

        int num;
        cin >> num;

        int root = sqrt(num);

        for(int i=1; i<=root; i++){

            if(num % i == 0){

                if(i * i == num){

                    factors[i]++;
                }
                else{

                    factors[i]++;
                    factors[num / i]++;
                }
            }
        }
    }

    unordered_map<int, int> :: iterator itr;
    int maxFactor = 0;

    for(int i=1; i<=1000000; i++){

        if(factors[i] >= 2){

            maxFactor = max(i, maxFactor);
        }
    }

    cout << maxFactor << endl;


    cout << endl;
    return 0;
}