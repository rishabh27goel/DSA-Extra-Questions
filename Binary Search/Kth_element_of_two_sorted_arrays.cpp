#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O((n1 + n2) * log(n1 + n2))  Space Complexity : O(n1 + n2)
// int kthElement(vector<int> &nums1, vector<int> &nums2, int k){

//     int n1 = nums1.size();
//     int n2 = nums2.size();

//     if(n1 + n2 < k)
//         return INT_MIN;

//     // Combining two arrays
//     vector<int> combined;

//     for(int i=0; i<n1; i++){

//         combined.push_back(nums1[i]);
//     }

//     for(int i=0; i<n2; i++){

//         combined.push_back(nums2[i]);
//     }

//     // Sort the combined array
//     sort(combined.begin(), combined.end());


//     return combined[k-1];
// }

// Method 2 : Merge two sorted array
// Time Complexity : O(n1 + n2)  Space Complexity : O(n1 + n2)
// int kthElement(vector<int> &nums1, vector<int> &nums2, int k){

//     int n1 = nums1.size();
//     int n2 = nums2.size();

//     if(n1 + n2 < k)
//         return INT_MIN;

//     // Combining two arrays
//     vector<int> combined;
    

//     int i = 0;
//     int j = 0;

//     while(i < n1 && j < n2){

//         if(nums1[i] == nums2[j]){

//             combined.push_back(nums1[i]);
//             combined.push_back(nums2[j]);

//             i++;
//             j++;
//         }
//         else if(nums1[i] < nums2[j]){

//             combined.push_back(nums1[i]);
//             i++;
//         }
//         else{

//             combined.push_back(nums2[j]);
//             j++;
//         }
//     }

//     while(i < n1){

//         combined.push_back(nums1[i]);
//         i++;
//     }

//     while(j < n2){

//         combined.push_back(nums2[j]);
//         j++;
//     }

//     return combined[k-1];
// }

// Method 3 : Merge two sorted array [With Counter]
// Time Complexity : O(n1 + n2)  Space Complexity : O(1)
// int kthElement(vector<int> &nums1, vector<int> &nums2, int k){

//     int n1 = nums1.size();
//     int n2 = nums2.size();

//     if(n1 + n2 < k)
//         return INT_MIN;

//     // Combining two arrays
//     int counter = 0;
//     int element = -1;

//     int i = 0;
//     int j = 0;

//     while(i < n1 && j < n2){

//         if(nums1[i] == nums2[j]){

//             if(counter == k-1)     
//                 element = nums1[i];

//             counter++;
//             i++;

//             if(counter == k-1)     
//                 element = nums2[j];

//             counter++;
//             j++;
//         }
//         else if(nums1[i] < nums2[j]){

//             if(counter == k-1)     
//                 element = nums1[i];
            
//             counter++;
//             i++;
//         }
//         else{

//             if(counter == k-1)     
//                 element = nums2[j];

//             counter++;
//             j++;
//         }
//     }

//     while(i < n1){

//         if(counter == k-1)     
//                 element = nums1[i];

//         counter++;
//         i++;
//     }

//     while(j < n2){

//         if(counter == k-1)     
//                 element = nums2[j];

//         counter++;
//         j++;
//     }

//     return element;
// }

// Method 4 : Using Binary Search
// Time Complexity : O(log(n1 + n2))  Space Complexity : O(1)
int kthElement(vector<int> &nums1, vector<int> &nums2, int k){

    int n1 = nums1.size();
    int n2 = nums2.size();

    int end = k;

    if(n1 < k)
        end = n1;

    
    int i = 0;
    int j = end;

    while(i <= j){

        int mid = i + (j - i) / 2;

        int split1 = mid;
        int split2 = k - split1;

        // Middle is not possible
        if(split2 > n2){

            i = mid + 1;
            continue;
        }

        int left1 = (split1 == 0 ? INT_MIN : nums1[split1-1]);
        int left2 = (split2 == 0 ? INT_MIN : nums2[split2-1]);
        int right1 = (split1 == n1 ? INT_MAX : nums1[split1]);
        int right2 = (split2 == n2 ? INT_MAX : nums2[split2]);

        // Split is Possible
        if(left1 <= right2 && left2 <= right1){

            return max(left1, left2);
        }
        else if(left1 > right2){

            j = mid - 1;
        }
        else{

            i = mid + 1;
        }
    }

    return 0;
}

int main()
{
    cout << "Enter size : ";
    int size1, size2;
    cin >> size1 >> size2;

    vector<int> arr1(size1);
    cout << "Enter array 1 : ";

    for(int i=0; i<size1; i++){

        cin >> arr1[i];
    }

    vector<int> arr2(size2);
    cout << "Enter array 2 : ";

    for(int i=0; i<size2; i++){

        cin >> arr2[i];
    }

    cout << "Enter k : ";
    int k;
    cin >> k;

    // Kth element of two sorted arrays
    int element = kthElement(arr1, arr2, k);

    cout << "Kth Element : " << element;


    cout << endl;
    return 0;
}