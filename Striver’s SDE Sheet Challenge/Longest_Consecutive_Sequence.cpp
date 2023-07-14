#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Using Set
// Time : O(n)  Space : O(n)
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    
    int result = 0;
    unordered_set<int> st;

    for(int i=0; i<n; i++){

        st.insert(arr[i]);
    }
    
    for(int i=0; i<n; i++){

      if (st.find(arr[i] - 1) == st.end()) {
      
          int start = arr[i];
          int c = 0;

          while (st.find(start) != st.end()) {

            st.erase(start);
            start = start + 1;
            c++;
          }

          result = max(c, result);
      }
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

    int length = lengthOfLongestConsecutiveSequence(arr, n);

    cout << "Length is : " << length;


    cout << endl;
    return 0;
}