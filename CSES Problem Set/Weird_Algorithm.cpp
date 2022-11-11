#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long n;
    cin >> n;

    vector<long> path;

    while(n != 1){

        path.push_back(n);

        if(n % 2 == 0){

            n = (n >> 1);
        }
        else{

            n = (3 * n) + 1;
        }
    }

    path.push_back(1);

    for(long i=0; i < (long) path.size(); i++){

        cout << path[i] << " ";
    }


    return 0;
}