#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Union of two arrays
// Method 1 : Using Set 
// Time Complexity : O((n1 + n2) * log(n1 + n2))  Space Complexity : O(n1 + n2) 
// vector<int> unionOfArray(vector<int> &arr1, vector<int> &arr2){

//     // Using Set [Will store elements in sorted order]
//     set<int> st;

//     for(int i=0; i<arr1.size(); i++){

//         st.insert(arr1[i]);
//     }

//     for(int i=0; i<arr2.size(); i++){

//         st.insert(arr2[i]);
//     }

//     // Get union from set
//     vector<int> unionArr;

//     for(int element : st){

//         unionArr.push_back(element);
//     }

//     return unionArr;
// }

// Method 2 : Single iteration of both array
// Time Complexity : O(n1 + n2)  Space Complexity : O(1) 
vector<int> unionOfArray(vector<int> &arr1, vector<int> &arr2){

    vector<int> unionArr;

    int i = 0;
    int j = 0;

    while(i < arr1.size() && j < arr2.size()){

        if(arr1[i] == arr2[j]){

            unionArr.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){

            unionArr.push_back(arr1[i]);
            i++;
        }   
        else{

            unionArr.push_back(arr2[j]);
            j++;
        }
    }

    while(i < arr1.size()){
       
        unionArr.push_back(arr1[i]);
        i++;
    }

    while(j < arr2.size()){
       
        unionArr.push_back(arr2[j]);
        j++;
    }


    return unionArr;
}

// Intersection of two arrays
// Method 1 : Using Set 
// Time Complexity : O((n1 + n2) * log(n1 + n2))  Space Complexity : O(n1 + n2) 
// vector<int> intersectionOfArray(vector<int> &arr1, vector<int> &arr2){

//     // Using Set [Will store elements in sorted order]
//     set<int> st;

//     for(int i=0; i<arr1.size(); i++){

//         st.insert(arr1[i]);
//     }

//     // Get union from set
//     vector<int> intersectionArr;

//     // Check for Intersection
//     for(int i=0; i<arr2.size(); i++){

//         if(st.find(arr2[i]) != st.end())
//             intersectionArr.push_back(arr2[i]);
//     }

//     return intersectionArr;
// }

// Method 2 : Single iteration of both array
// Time Complexity : O(n1 + n2)  Space Complexity : O(1) 
vector<int> intersectionOfArray(vector<int> &arr1, vector<int> &arr2){

    vector<int> intersectionArr;

    int i = 0;
    int j = 0;

    while(i < arr1.size() && j < arr2.size()){

        if(arr1[i] == arr2[j]){

            intersectionArr.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){

            i++;
        }
        else{

            j++;
        }
    }


    return intersectionArr;
}

int main()
{
    cout << "Enter size : ";
    int size1, size2;
    cin >> size1 >> size2;

    cout << "Enter array 1 : ";
    vector<int> arr1(size1);

    for(int i=0; i<size1; i++){

        cin >> arr1[i];
    }

    cout << "Enter array 2 : ";
    vector<int> arr2(size2);

    for(int i=0; i<size2; i++){

        cin >> arr2[i];
    }

    // Union and Intersection of two arrays
    vector<int> unionArr = unionOfArray(arr1, arr2);

    cout << "Union Array : ";

    for(int i=0; i<unionArr.size(); i++){

        cout << unionArr[i] << " ";
    }

    vector<int> intersectionArr = intersectionOfArray(arr1, arr2);

    cout << "\nIntersection Array : ";

    for(int i=0; i<intersectionArr.size(); i++){

        cout << intersectionArr[i] << " ";
    }

    cout << endl;
    return 0;
}