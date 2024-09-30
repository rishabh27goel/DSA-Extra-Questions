#include <iostream>
#include <vector>
using namespace std;

// class CustomStack {
// public:
//     stack<int> st;
//     int size;

//     CustomStack(int maxSize) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);

//         this->size = maxSize;
//     }
    
//     void push(int x) {
//         if(st.size() == size)   
//             return;

//         st.push(x);
//     }
    
//     int pop() {
//         if(st.empty())  return -1;
//         int top = st.top();
//         st.pop();
//         return top;
//     }
    
//     void increment(int k, int val) {
//         stack<int> tmp;
//         while(!st.empty()) {
//             tmp.push(st.top());
//             st.pop();
//         }

//         while(!tmp.empty() && k > 0) {
//             int updatedVal = tmp.top() + val;
//             st.push(updatedVal);
//             tmp.pop();
//             k--;
//         }

//         while(!tmp.empty()) {
//             st.push(tmp.top());
//             tmp.pop();
//         }
//     }
// };

// /**
//  * Your CustomStack object will be instantiated and called as such:
//  * CustomStack* obj = new CustomStack(maxSize);
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * obj->increment(k,val);
//  */

class CustomStack {
public:
    vector<int> stack;
    int top;
    int size;

    CustomStack(int maxSize) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        stack.resize(maxSize);
        this->size = maxSize;
        this->top = -1;
    }
    
    void push(int x) {
        if(top + 1 == size)   
            return;

        stack[++top] = x;
    }
    
    int pop() {
        if(top == -1)  return -1;

        int val = stack[top--];
        return val;
    }
    
    void increment(int k, int val) {
        if(top == -1)  return;

        for(int j = 0; j <= min(top, k-1); j++) {
            stack[j] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */