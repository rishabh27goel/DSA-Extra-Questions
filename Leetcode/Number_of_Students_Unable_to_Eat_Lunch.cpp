#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int countStudents(vector<int>& students, vector<int>& sandwiches) {

    //     int n = students.size();

    //     queue<int> q;   
    //     for(int i=0; i<n; i++){
    //         q.push(students[i]);
    //     }

    //     for(int i=0; i<n; i++){
            
    //         int c = q.size();
    //         while(c > 0 && q.front() != sandwiches[i]){
    //             q.push(q.front());
    //             q.pop();
    //             c--;
    //         }

    //         if(c == 0)
    //             return q.size();

    //         q.pop();
    //     }

    //     return q.size();
    // }

    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        int n = students.size();

        int circular = 0;
        int square = 0;
        for(int i=0; i<n; i++){
            if(students[i])
                square++;
            else
                circular++;
        }

        for(int i=0; i<n; i++){
            if(sandwiches[i]){
                if(square)
                    square--;
                else
                    return circular;
            }
            else {
                if(circular)
                    circular--;
                else
                    return square;
            }
        }

        return square + circular;
    }
};