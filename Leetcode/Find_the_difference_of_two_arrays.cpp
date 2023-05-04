#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector< vector<int> > findDiff(vector<int> &nums1, vector<int> &nums2){

    int n1 = nums1.size();
    int n2 = nums2.size();

    vector< vector<int> > result(2);
    unordered_set<int> st1;
    unordered_set<int> st2;

    for(int i=0; i<n1; i++){

        st1.insert(nums1[i]);
    }

    for(int i=0; i<n2; i++){

        st2.insert(nums2[i]);
    }

    for(auto itr = st1.begin(); itr != st1.end(); itr++){

        if(st2.find(*(itr)) == st2.end()){

            result[0].push_back(*(itr));
        }
    }

    for(auto itr = st2.begin(); itr != st2.end(); itr++){

        if(st1.find(*(itr)) == st1.end()){

            result[1].push_back(*(itr));
        }
    }

    return result;
}

int main()
{
    cout << "Enter size : ";
    int size1, size2;
    cin >> size1 >> size2;

    vector<int> nums1(size1);
    vector<int> nums2(size2);

    for(int i=0; i<size1; i++){

        cin >> nums1[i];
    }

    for(int i=0; i<size2; i++){

        cin >> nums2[i];
    }

    vector< vector<int> > result = findDiff(nums1, nums2);

    cout << "Difference of arrays : " << endl;

    for(int i=0; i<result.size(); i++){

        for(int j=0; j<result.size(); j++){

            cout << result[i][j] << " ";
        }

        cout << endl;
    }


    cout << endl;
    return 0;
}