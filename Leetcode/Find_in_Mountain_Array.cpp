#include <iostream>
#include <vector>
using namespace std;

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
    
    public:
        int get(int index);
        int length();
        
};
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = mountainArr.length();

        // Find the mountain index
        int mountainIndex = -1;
        int i = 0;
        int j = n-1;

        while(i < j){

            int mid = i + (j - i) / 2;

            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){

                i = mid + 1;
            }
            else{

                j = mid;
            }
        }


        // Find the target now
        mountainIndex = i;

        // Left Search
        i = 0;
        j = mountainIndex;

        while(i <= j){

            int mid = i + (j - i) / 2;

            if(mountainArr.get(mid) == target){

                return mid;
            }
            else if(mountainArr.get(mid) > target){

                j = mid - 1;
            }
            else{

                i = mid + 1;
            }
        }

        // Right Search
        i = mountainIndex;
        j = n-1;

        while(i <= j){

            int mid = i + (j - i) / 2;

            if(mountainArr.get(mid) == target){

                return mid;
            }
            else if(mountainArr.get(mid) > target){

                i = mid + 1;
            }
            else{

                j = mid - 1;
            }
        }
    
        return -1;
    }
};