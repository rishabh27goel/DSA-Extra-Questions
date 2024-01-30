#include <iostream>
#include <stack>
using namespace std;

// class MyQueue {
// public:

//     stack<int> st1;
//     stack<int> st2;

//     MyQueue() {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);
//     }
    
//     void push(int x) {
//         st1.push(x);
//     }
    
//     int pop() {
        
//         while(!st1.empty()){
//             st2.push(st1.top());
//             st1.pop();
//         }

//         int val = st2.top();
//         st2.pop();

//         while(!st2.empty()){
//             st1.push(st2.top());
//             st2.pop();
//         }

//         return val;
//     }
    
//     int peek() {
        
//         while(!st1.empty()){
//             st2.push(st1.top());
//             st1.pop();
//         }

//         int val = st2.top();

//         while(!st2.empty()){
//             st1.push(st2.top());
//             st2.pop();
//         }

//         return val;
//     }
    
//     bool empty() {
        
//         return st1.empty();
//     }
// };

// /**
//  * Your MyQueue object will be instantiated and called as such:
//  * MyQueue* obj = new MyQueue();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->peek();
//  * bool param_4 = obj->empty();
//  */

class MyQueue {
public:

    stack<int> st1;
    stack<int> st2;

    MyQueue() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    void push(int x) {
        while(!st2.empty()){

            st1.push(st2.top());
            st2.pop();
        }

        st2.push(x);
        while(!st1.empty()){

            st2.push(st1.top());
            st1.pop();
        }
    }
    
    int pop() {
        int top = st2.top();
        st2.pop();
        return top;
    }
    
    int peek() {
        return st2.top();
    }
    
    bool empty() {
        return st2.empty();
    }
};

// /**
//  * Your MyQueue object will be instantiated and called as such:
//  * MyQueue* obj = new MyQueue();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->peek();
//  * bool param_4 = obj->empty();
//  */