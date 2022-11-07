#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Checking all possible maximum pages
// Time Complexity : O(n * sum of array)   Space Complexity : O(1)
// bool allocationPossible(int n, vector<int> &arr, int m, int sum){

//     int curr = 0;

//     int i = 0;
//     int k = 0;

//     while(i < n){

//         if(arr[i] > sum)
//             return false;

//         if(curr + arr[i] > sum){

//             k++;
//             curr = arr[i];

//             if(k >= m)
//                 return false;
//         }
//         else{

//             curr += arr[i];
//         }

//         i++;
//     }

//     return true;
// }

// int bookAllocationProblem(vector<int> &books, int m){

//     int n = books.size();

//     // Find the sum range [max element to total sum]
//     int sum = 0;
//     int maxElement = INT_MIN;

//     for(int i=0; i<n; i++){

//         maxElement = max(books[i], maxElement);
//         sum += books[i];
//     }

//     // Check for all pages in range
//     int maxSplit = INT_MIN;

//     for(int i=maxElement; i<=sum; i++){

//         if(allocationPossible(n, books, m, i)){

//             maxSplit = i;
//             break;
//         }
//     }

//     if(maxSplit == INT_MIN)
//         return -1;

//     return maxSplit;
// }

// Method 2 : Binary Search
// Time Complexity : O(n * log(sum of array))   Space Complexity : O(1)
bool allocationPossible(int n, vector<int> &arr, int m, int sum){

    int curr = 0;

    int i = 0;
    int k = 0;

    while(i < n){

        if(arr[i] > sum)
            return false;

        if(curr + arr[i] > sum){

            k++;
            curr = arr[i];

            if(k >= m)
                return false;
        }
        else{

            curr += arr[i];
        }

        i++;
    }

    return true;
}

int bookAllocationProblem(vector<int> &books, int m){

    int n = books.size();

    // Find the sum range [max element to total sum]
    int sum = 0;
    int maxElement = INT_MIN;

    for(int i=0; i<n; i++){

        maxElement = max(books[i], maxElement);
        sum += books[i];
    }

    // Check for all pages in range
    int maxSplit = INT_MIN;

    int i = maxElement;
    int j = sum;

    while(i <= j){

        int mid = i + (j - i) / 2;

        if(allocationPossible(n, books, m, mid)){

            maxSplit = mid;
            j = mid - 1;
        }
        else {

            i = mid + 1;
        }
    }


    if(maxSplit == INT_MIN)
        return -1;

    
    return maxSplit;
}

int main()
{
    cout << "Enter number of books : ";
    int n;
    cin >> n;

    vector<int> books(n);
    cout << "Enter books : ";

    for(int i=0; i<n; i++){

        cin >> books[i];
    }

    cout << "Enter number of students : ";
    int k;
    cin >> k;


    // Book Allocation Problem
    int maxPages = bookAllocationProblem(books, k);

    cout << "Maximum Pages : " << maxPages;


    cout << endl;
    return 0;
}