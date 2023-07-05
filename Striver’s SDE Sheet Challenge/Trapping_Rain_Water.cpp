#include <iostream>
using namespace std;

// Extra Space
// Time : O(n)  Space : O(n)
// int trap(vector<int>& height) {
  
//     int n = height.size();

//     vector<int> leftMax(n);

//     int maxVal = INT_MIN;

//     for(int i=0; i<n; i++){

//         maxVal = max(maxVal, height[i]);
//         leftMax[i] = maxVal;
//     }

//     maxVal = INT_MIN;

//     int result = 0;

//     for(int i=n-1; i>=0; i--){

//         maxVal = max(maxVal, height[i]);

//         result += (min(leftMax[i], maxVal) - height[i]) ;
//     }

//     return result;
// }

// Constant Space
// Time : O(n)  Space : O(1)
int trap(vector<int>& height) {
  
    int n = height.size();

    vector<int> leftMax(n);

    int maxVal = INT_MIN;

    for(int i=0; i<n; i++){

        maxVal = max(maxVal, height[i]);
        leftMax[i] = maxVal;
    }

    maxVal = INT_MIN;

    int result = 0;

    for(int i=n-1; i>=0; i--){

        maxVal = max(maxVal, height[i]);

        result += (min(leftMax[i], maxVal) - height[i]) ;
    }

    return result;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }


    int water = trap(arr);

    cout << "Water Trapped : " << water;



    cout << endl;
    return 0;
}