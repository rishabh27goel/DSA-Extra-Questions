#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Recursion Method
// Time Complexity : O()  Space Complexity : O()
int burstBalloon(vector<int> & ){


}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;
    
    vector<int> nums(size);
    cout << "Enter array : ";

    for(int i=0; i<size; i++){

        cin >> nums[i];
    }

    // Burst Balloon
    int coins = burstBalloon(nums);

    cout << "Maximum Coins : " << coins;


    cout << endl;
    return 0;
}