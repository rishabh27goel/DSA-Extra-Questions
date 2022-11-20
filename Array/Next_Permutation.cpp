#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Generate all possibles 
// Time Complexity : O(!n * log(!n))  Space Complexity : O(!n)
// void generatePermutation(vector<int> &nums, int index, vector< vector<int> > &permutation){

//     if(index == nums.size()-1){

//         permutation.push_back(nums);
//         return;
//     }


//     for(int i=index; i<nums.size(); i++){

//         swap(nums[index], nums[i]);

//         generatePermutation(nums, index+1, permutation);

//         // Backtracking
//         swap(nums[index], nums[i]);
//     }
// }

// bool isEqual(vector<int> &v1, vector<int> &v2){

//     for(int i=0; i<v1.size(); i++){

//         if(v1[i] != v2[i])
//             return false;
//     }

//     return true;
// }

// vector<int> nextPermutation(vector<int> &nums){

//     if(nums.size() <= 1)
//         return nums;


//     vector<int> original = nums;

//     // Sort the array
//     sort(nums.begin(), nums.end());


//     // Generate Permutations
//     vector< vector<int> > permutation;

//     generatePermutation(nums, 0, permutation);

//     sort(permutation.begin(), permutation.end());


//     // Find the next permutation
//     for(int i=0; i<permutation.size(); i++){

//         if(isEqual(permutation[i], original)){

//             int ind = (i + 1) % permutation.size();

//             return permutation[ind];
//         }
//     }

//     return nums;
// }

// Method 2 : Linear Method
// Time Complexity : O(n)  Space Complexity : O(1)
void reverseArr(vector<int> &nums, int ind){

    int i = ind;
    int j = nums.size()-1;

    while(i <= j){

        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

vector<int> nextPermutation(vector<int> &nums){

    int n = nums.size();

    int index = -1;

    for(int i=n-2; i>=0; i--){

        if(nums[i] < nums[i+1]){

            index = i;
            break;
        }
    }

    if(index != -1){

        for(int i=n-1; i>index; i--){

            if(nums[i] > nums[index]){

                swap(nums[i], nums[index]);
                break;
            }
        }
    }

    // Reverse the array
    reverseArr(nums, index+1);

    return nums;
}

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;

    cout << "Enter array : ";
    vector<int> nums(n);

    for(int i=0; i<n; i++){

        cin >> nums[i];
    }

    // Next Permutation
    vector<int> next = nextPermutation(nums);

    cout << "Next Permutation : ";

    for(int i=0; i<n; i++){

        cout << next[i] << " ";
    }

    cout << endl;
    return 0;
}