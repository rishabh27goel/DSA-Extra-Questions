#include <iostream>
#include <vector>
using namespace std;

// Method : Sorting & Two Pointer [Greedy Approach]
int boatsToSave(vector<int> &arr, int limit){

    int n = arr.size();

    // Sorting the array
    sort(arr.begin(), arr.end());

    int total = 0;

    int i = 0;
    int j = n-1;

    while(i <= j){

        // Find the best fit for two spaces in the boat at each step
        if(arr[i] + arr[j] <= limit){

            // Take both
            i++;
            j--;
        }
        else{

            // Take last person 
            j--;
        }

        total++;
    }


    return total;
} 

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> arr(size);

    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    cout << "Enter limits : ";
    int limits;
    cin >> limits;


    // Boats to Save People
    int total = boatsToSave(arr, limits);

    cout << "Total is : " << total;


    cout << endl;
    return 0;
}