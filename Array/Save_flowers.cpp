#include <iostream>
#include <vector>
using namespace std;

// Method : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1) 
int saveFlower(vector<int> &arr, string &str){

    int n = arr.size();

    int result = 0;
    int sum  = 0;

    bool flag = 0;
    int minNum = INT_MAX;

    for(int i=n-1; i>=0; i--){

        if(str[i] == '1'){

            sum += arr[i];
            minNum = min(arr[i], minNum);

            flag = 1;
        }
        else{

            if(flag){

                sum += arr[i];
                minNum = min(arr[i], minNum);

                result += (sum - minNum);
                minNum = INT_MAX;
                sum = 0;

                flag = 0;
            }
        }
    }

    if(flag)
        result += sum;

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

    cout << "Enter Input String : ";
    string str;
    cin >> str;

    // Save Flower
    int maxFlower = saveFlower(arr, str);

    cout << "Maximum Flower : " << maxFlower;


    cout << endl;
    return 0;
}