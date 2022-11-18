#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Method 1 : Using Unordered Set 
// Time Complexity : O(n1 + n2 + n3)  Space Complexity : O(n1 + n2) 
// vector<int> intersectionOfArrays(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3){

//     vector<int> common;

//     unordered_set<int> first;
//     unordered_set<int> second;

//     for(int i=0; i<arr1.size(); i++){

//         first.insert(arr1[i]);
//     }

//     for(int i=0; i<arr2.size(); i++){

//         second.insert(arr2[i]);
//     }

//     // Check for common elements
//     int i = 0;

//     while(i < arr3.size()){

//         if(first.find(arr3[i]) != first.end() && second.find(arr3[i]) != second.end()){

//             common.push_back(arr3[i]);
//         }

//         int value = arr3[i];

//         while(i < arr3.size() && arr3[i] == value){

//             i++;
//         }
//     }

//     return common;
// }

// Method 2 : Without Using Extra Space
// Time Complexity : O(n1 + n2 + n3)  Space Complexity : O(1) 
vector<int> intersectionOfArrays(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3){

    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = arr3.size();


    vector<int> common;

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < n1 && j < n2 && k < n3){

        if(arr1[i] < arr2[j] && arr1[i] < arr3[k]){

            i++;
        }
        else if(arr2[j] < arr3[k] && arr2[j] < arr1[i]){

            j++;
        }
        else if(arr3[k] < arr2[j] && arr3[k] < arr1[i]){

            k++;
        }
        else if(arr1[i] == arr2[j] && arr1[i] < arr3[k]){

            i++;
            j++;
        }
        else if(arr2[j] == arr3[k] && arr2[j] < arr1[i]){

            j++;
            k++;
        }
        else if(arr3[k] == arr1[i] && arr3[k] < arr2[j]){

            k++;
            i++;
        }
        else{

            common.push_back(arr1[i]);

            int value = arr1[i];
    
            while(i < n1 && value == arr1[i]){
                
                i++;
            }
            
            while(j < n2 && value == arr2[j]){
                
                j++;
            }
            
            while(k < n3 && value == arr3[k]){
                
                k++;
            }
        }
    }

    return common;
}

int main()
{
    cout << "Enter size : ";
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    cout << "Enter array 1 : ";
    vector<int> arr1(n1);

    for(int i=0; i<n1; i++){

        cin >> arr1[i];
    }

    cout << "Enter array 2 : ";
    vector<int> arr2(n2);

    for(int i=0; i<n2; i++){

        cin >> arr2[i];
    }

    cout << "Enter array 3 : ";
    vector<int> arr3(n3);

    for(int i=0; i<n3; i++){

        cin >> arr3[i];
    }

    // Intersection of three sorted arrays
    vector<int> common = intersectionOfArrays(arr1, arr2, arr3);

    cout << "Intersection of 3 Sorted Arrays : ";

    for(int i=0; i<common.size(); i++){

        cout << common[i] << " ";
    }


    cout << endl;
    return 0;
}