#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Brute Force
    // bool checkIfExist(vector<int>& arr) {
    //     int n = arr.size();

    //     for(int i = 0; i < n; i++) {
    //         for(int j = i + 1; j < n; j++) {
    //             if(arr[i] * 2 == arr[j] || arr[j] * 2 == arr[i])
    //                 return true;
    //         }
    //     }

    //     return false;
    // }

    // int findElement(vector<int> &arr, int start, int end, int target) {
    //     while(start <= end) {
    //         int mid = start + (end - start) / 2;
    //         if(arr[mid] * 2 == target) {
    //             return mid;
    //         }   
    //         else if(arr[mid] * 2 > target) {
    //             end = mid - 1;
    //         }
    //         else {
    //             start = mid + 1;
    //         }
    //     }
    //     return -1;
    // }

    // bool checkIfExist(vector<int>& arr) {
    //     int n = arr.size();

    //     sort(arr.begin(), arr.end());

    //     for(int i = 0; i < n; i++) {
    //         int idx = findElement(arr, 0, n-1, arr[i]);
    //         if(idx != -1 && idx != i) {
    //             return true;
    //         } 
    //     }

    //     return false;
    // }

    // int findElement(vector<int> &arr, int start, int end, int target) {
    //     while(start <= end) {
    //         int mid = start + (end - start) / 2;
    //         if(arr[mid] * 2 == target) {
    //             return mid;
    //         }   
    //         else if(arr[mid] * 2 > target) {
    //             end = mid - 1;
    //         }
    //         else {
    //             start = mid + 1;
    //         }
    //     }
    //     return -1;
    // }

    // bool checkIfExist(vector<int>& arr) {
    //     int n = arr.size();

    //     sort(arr.begin(), arr.end());

    //     for(int i = 0; i < n; i++) {
    //         int idx = findElement(arr, 0, n-1, arr[i]);
    //         if(idx != -1 && idx != i) {
    //             return true;
    //         } 
    //     }

    //     return false;
    // }

    bool checkIfExist(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = arr.size();

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        for(int i = 0; i < n; i++) {
            int doubleVal = arr[i] * 2;

            if(arr[i] == 0 && mp[arr[i]] > 1)
                return true;

            if(doubleVal != arr[i] && mp.find(doubleVal) != mp.end())
                return true;
        }

        return false;
    }
};