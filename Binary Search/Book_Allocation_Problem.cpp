#include <iostream>
#include <vector>
using namespace std;

int bookAllocationProblem(vector<int> &books, int k){


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