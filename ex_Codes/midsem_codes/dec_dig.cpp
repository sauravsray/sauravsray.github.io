#include <iostream>
#include <cmath>
using namespace std;


int main ()
{
	int n;
	cout << "Enter a positive interger" << endl;
	cin >> n;
	int count = 1;

	int res;
	int temp;
	while (res != n) {
		temp = pow(10, count);
		res = n % temp;
		count++;
	}
	cout << "The number of digits is = " << --count << endl;
	return 0;
}
