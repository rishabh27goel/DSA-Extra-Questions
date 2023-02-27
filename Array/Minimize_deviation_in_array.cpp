#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Using Priority Queue
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
// int findMinimumDeviation(vector<int> &arr){

//     int n = arr.size();

//     priority_queue<int> q;
//     int minDev = INT_MAX;
//     int minNum = INT_MAX;

//     for(int i=0; i<n; i++){

//         arr[i] & 1 ? q.push(arr[i] * 2) : q.push(arr[i]);   
//         minNum = arr[i] & 1 ? min(arr[i] * 2, minNum) : min(arr[i], minNum); 
//     }

//     while(!(q.top() & 1)){

//         int top = q.top();
//         q.pop();
//         q.push(top / 2);

//         minDev = min(top - minNum, minDev);
//         minNum = min(top / 2, minNum);
//     }

//     return min(q.top() - minNum, minDev);;
// }

// Method 2 : Sorting the vector
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
int findMinimumDeviation(vector<int> &arr){

    int n = arr.size();

    int maxOdd = INT_MIN;

    for(int i=0; i<n; i++){

        int val = arr[i];

        while(val % 2 == 0)
            val >>= 1;

        maxOdd = max(val, maxOdd);
    }

    vector<int> tmp;

    for(int i=0; i<n; i++){

        if(arr[i] % 2 == 1){

            tmp.push_back(arr[i]);
        }
        else{

            int val = arr[i];
            val >>= 1;

            while(val > maxOdd){

                val >>= 1;
            }

            tmp.push_back(val);
        }
    }

    sort(tmp.begin(), tmp.end());

    int result = tmp[n-1] - tmp[0];

    for(int i=0; i<n-1; i++){

        result = min(result, max(tmp[n-1], tmp[i] * 2) - min(tmp[0] * 2, tmp[i+1]));
    }

    return result;
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