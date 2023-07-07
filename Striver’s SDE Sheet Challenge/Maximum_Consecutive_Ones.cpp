#include <iostream>
#include <vector>
using namespace std;

// Sliding Window
// Time : O(n)  Space : O(1)
int longestSubSeg(vector<int> &arr , int n, int k){

    int result = 0;
    int c = 0;

    int i = 0;
    int j = 0;

    while (j < n) {
    
        if(arr[j] == 0)
            c++;

        while (i <= j && c > k) {
        
            if(arr[i] == 0)
                c--;

            i++;
        }

        result = max(j - i + 1, result);
        j++;
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

    cout << "Enter k : ";
    int k;
    cin >> k;


    int maxOnes = longestSubSeg(arr, n, k);

    cout << "Maximum Ones : " << maxOnes;


    cout << endl;
    return 0;
}