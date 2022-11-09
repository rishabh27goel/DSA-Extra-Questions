#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O((n1 + n2) * log(n1 + n2))  Space Complexity : O(n1 + n2)
// double medianTwoSortedArray(vector<int> &nums1, vector<int> &nums2){

//     int n1 = nums1.size();
//     int n2 = nums2.size();

//     int n = n1 + n2;

//     vector<int> combined;

//     for(int i=0; i<n1; i++){

//         combined.push_back(nums1[i]);
//     }

//     for(int i=0; i<n2; i++){

//         combined.push_back(nums2[i]);
//     }


//     // Sort the combined array
//     sort(combined.begin(), combined.end());

//     // Even
//     if(n % 2 == 0){

//         return (combined[n/2] + combined[(n-1)/2]) / 2.0;
//     }
//     // Odd
//     else{

//         return combined[n/2];
//     }
// }

// Method 2 : Merge Two Sorted Array
// Time Complexity : O(n1 + n2)  Space Complexity : O(n1 + n2)
// double medianTwoSortedArray(vector<int> &nums1, vector<int> &nums2){

//     int n1 = nums1.size();
//     int n2 = nums2.size();

//     int n = n1 + n2;

//     // Merge Array
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


//     // Even
//     if(n % 2 == 0){

//         return (combined[n/2] + combined[(n-1)/2]) / 2.0;
//     }
//     // Odd
//     else{

//         return combined[n/2];
//     }
// }

// Method 3 : Merge Two Sorted Array
// Time Complexity : O(n1 + n2)  Space Complexity : O(1)
// void updateMedian(int n, int counter, int &first, int &second, int value){

//     if((n-1) / 2 == counter)
//         first = value;
        
//     if(n / 2 == counter)
//         second = value;
// }

// double medianTwoSortedArray(vector<int> &nums1, vector<int> &nums2){

//     int n1 = nums1.size();
//     int n2 = nums2.size();

//     int n = n1 + n2;

//     int first = -1;
//     int second = -1;

//     // Merge Array
//     vector<int> combined;

//     int counter = 0;
//     int i = 0;
//     int j = 0;

//     cout << n << " ";

//     while(i < n1 && j < n2){

//         if(nums1[i] == nums2[j]){

//             combined.push_back(nums1[i]);
//             combined.push_back(nums2[j]);

//             updateMedian(n, counter, first, second, nums1[i]);

//             counter++;
//             i++;

//             updateMedian(n, counter, first, second, nums2[j]);

//             counter++;
//             j++;
//         }
//         else if(nums1[i] < nums2[j]){

//             combined.push_back(nums1[i]);

//             updateMedian(n, counter, first, second, nums1[i]);

//             counter++;
//             i++;
//         }
//         else{

//             combined.push_back(nums2[j]);

//             updateMedian(n, counter, first, second, nums2[j]);

//             counter++;
//             j++;
//         }
//     }

//     while(i < n1){

//         updateMedian(n, counter, first, second, nums1[i]);

//         combined.push_back(nums1[i]);

//         counter++;
//         i++;
//     }

//     while(j < n2){

//         updateMedian(n, counter, first, second, nums2[j]);

//         combined.push_back(nums2[j]);

//         counter++;
//         j++;
//     }

//     // Even
//     if(n % 2 == 0){

//         return (first + second) / 2.0;
//     }
//     // Odd
//     else{

//         return first / 1.0;
//     }
// }

// Method 4 : Using Binary Search
// Time Complexity : O(log(n1 + n2))  Space Complexity : O(1)
double medianTwoSortedArray(vector<int> &nums1, vector<int> &nums2){

    int n1 = nums1.size();
    int n2 = nums2.size();

    if(n1 > n2)
        return medianTwoSortedArray(nums2, nums1);


    // Apply Binary Search on different splits possible
    // We will always try to take nums1 as smaller size array 
    int i = 0;
    int j = n1;

    int total = (n1 + n2 + 1) / 2;

    while(i <= j){

        int mid = i + (j - i) / 2;

        int split1 = mid;
        int split2 = total - split1;

        int left1 = (split1 == 0 ? INT_MIN : nums1[split1-1]);
        int left2 = (split2 == 0 ? INT_MIN : nums2[split2-1]);
        int right1 = (split1 == n1 ? INT_MAX : nums1[split1]);
        int right2 = (split2 == n2 ? INT_MAX : nums2[split2]);

        // If split is possible
        if(left1 <= right2 && left2 <= right1){

            if((n1 % n2) % 2 == 0){

                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else{

                return max(left1, left2) / 1.0;
            }
        }
        else if(left1 > right2){

            j = mid - 1;
        }
        else{

            i = mid + 1;
        }
    }

    return 0.0;
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

    // Median of Two Sorted Array
    double median = medianTwoSortedArray(arr1, arr2);

    cout << "Median of two array : " << median;


    cout << endl;
    return 0;
}