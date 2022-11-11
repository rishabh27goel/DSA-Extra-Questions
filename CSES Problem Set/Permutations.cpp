#include <iostream>
#include <vector>
using namespace std;

vector<int> findPermutations(int n){

    vector<int> permu;

    if(n == 1)
        return {1};

    if(n <= 3)
        return permu;
    

    // Odd Adding
    int i = n;
    
    if(n % 2 == 0)
        i--;

    while(i >= 1){

        permu.push_back(i);
        i -= 2;
    }

    // Even Adding
    i = n;

    if(n & 1)
        i--;

    while(i >= 1){

        permu.push_back(i);
        i -= 2;
    }

    return permu;
}

int main()
{
    int n;
    cin >> n;


    vector<int> arr = findPermutations(n);

    if(!arr.empty()){

        for(int i=0; i< n; i++){

            cout << arr[i] << " ";
        }
    }
    else{

        cout << "NO SOLUTION";
    }
    
    return 0;
}