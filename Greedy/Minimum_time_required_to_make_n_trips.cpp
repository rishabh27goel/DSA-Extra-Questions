#include <iostream>
#include <vector>
using namespace std;

// Method : Using Binary Search
// Time Complexity : O(log(possible answers))  Space Complexity : O(1)
bool isMatch(int trips, vector<int> &cabs, int match){

    int n = cabs.size();

    int c = 0;

    for(int i=0; i<n; i++){

        c += (match / cabs[i]);

        if(c >= trips)
            return true;
    }

    return false;
}

int minimumTimeRequired(int trips, vector<int> &cabs){

    int n = cabs.size();

    int minTime = INT_MAX;

    int start = 1;
    int end = INT_MAX;

    while(start <= end){

        int mid = start + (end - start) / 2;

        // If match is found then check for less possible time
        if(isMatch(trips, cabs, mid)){

            end = mid - 1;
            minTime = min(mid, minTime);
        }
        else{

            start = mid + 1;
        }
    }

    return minTime;
}

int main()
{
    cout << "Enter number of trips : ";
    int trips;
    cin >> trips;

    cout << "Enter number of cabs : ";
    int n;
    cin >> n;

    vector<int> cabs(n);

    for(int i=0; i<n; i++){

        cin >> cabs[i];
    }

    // Minimum time required to make n trips
    int minTime = minimumTimeRequired(trips, cabs);

    cout << "Minimum Time : " << minTime;

    cout << endl;
    return 0;
}