#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method : Using Priority Queue
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
int findMinimumDeviation(vector<int> &arr){

    int n = arr.size();

    priority_queue<int> q;
    int minDev = INT_MAX;
    int minNum = INT_MAX;

    for(int i=0; i<n; i++){

        arr[i] & 1 ? q.push(arr[i] * 2) : q.push(arr[i]);   
        minNum = arr[i] & 1 ? min(arr[i] * 2, minNum) : min(arr[i], minNum); 
    }

    while(!(q.top() & 1)){

        int top = q.top();
        q.pop();
        q.push(top / 2);

        minDev = min(top - minNum, minDev);
        minNum = min(top / 2, minNum);
    }

    return min(q.top() - minNum, minDev);;
}

int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    int deviation = findMinimumDeviation(arr);

    cout << "Minimum Deviation : " << deviation;


    cout << endl;
    return 0;
}