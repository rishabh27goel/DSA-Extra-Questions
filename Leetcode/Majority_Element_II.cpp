#include <iostream>
#include <vector>
using namespace std;

// Method : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
vector<int> majorityElement(vector<int> &arr){

    int n = arr.size();

    int first = INT_MAX;
    int second = INT_MAX;

    int c1 = 0;
    int c2 = 0;

    for(int i=0; i<n; i++){

        if(first == arr[i])
            c1++;

        else if(second == arr[i])
            c2++;
        
        else if(c1 == 0){

            first = arr[i];
            c1 = 1;
        }    
        else if(c2 == 0){

            second = arr[i];
            c2 = 1;
        }            
        else{

            c1--;   
            c2--;
        }
    }

    c1 = 0;
    c2 = 0;

    for(int i=0; i<n; i++){

        if(first == arr[i])
            c1++;

        if(second == arr[i])
            c2++;
    }

    vector<int> result;

    if(c1 > n/3)
        result.push_back(first);

    if(c2 > n/3)
        result.push_back(second);


    cout << c1 << " " << c2 << " ";

    return result;
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

    // Majority Element
    vector<int> element = majorityElement(arr);

    cout << "Majority Element : ";

    if(element.size() >= 1)
        cout << element[0] << " ";

    if(element.size() >= 2)
        cout << element[1] << " ";


    cout << endl;
    return 0;
}