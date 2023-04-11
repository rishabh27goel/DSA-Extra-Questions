#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method : Using sorting and hashmap
// Time Complexity : O(n)  Space Complexity : O(n)
bool handOfStraights(vector<int> &arr, int groupSize){

    int n = arr.size();

    // Sort the array
    sort(arr.begin(), arr.end());

    
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){

        mp[arr[i]]++;
    }


    int i = 0;

    while(i < n){

        if(mp[arr[i]] == 0){

            i++;
            continue;
        }

        int val = arr[i];
        int size = groupSize;

        while(size){

            mp[val]--;

            // Not valid
            if(mp[val] < 0)
                return false;

            val++;
            size--;
        }

        i++;
    }

    return true;
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

    cout << "Enter group size : ";
    int groupSize;
    cin >> groupSize;


    // Hand of straights
    bool valid = handOfStraights(arr, groupSize);

    if(valid){

        cout << "Straights Hands !!";
    }
    else{

        cout << "Not Straights Hands !!";    
    }



    cout << endl;
    return 0;
}