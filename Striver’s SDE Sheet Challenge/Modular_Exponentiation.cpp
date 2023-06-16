#include <iostream>
using namespace std;

#define ll long long int

// Linear method
// Time : O(n)  Space : O(1)
// int modularExponentiation(int x, int n, int m) {

//   ll result = 1;

//   for(int i=0; i<n; i++){

//     result = (result % m * x % m) % m;
//   }

//   return (int) result;
// }

// Bit Manipulation 
// Time : O(log(n))  Space : O(1)
int modularExponentiation(int x, int n, int m) {

  ll result = 1;
  ll val = x;

  while (n != 0) {
  
	  if(n & 1)
		result = (result % m * val % m) % m;
  
	  val = (val % m * val % m) % m;
	  n >>= 1;
  }

  return (int) result;
}

int main()
{
    cout << "Enter x : ";
    int x;
    cin >> x;

    cout << "Enter n : ";
    int n;
    cin >> n;

    cout << "Enter mod : ";
    int m;
    cin >> m;

    int power = modularExponentiation(x, n, m);

    cout << "Result is : " << power;


    cout << endl;
    return 0;
}