
#include<iostream>
using namespace std ;

int main ()
{
	int n;
	cout <<"enter a value for the number of elements" << endl;
	cin >> n;
	int *num;
	num = new int [n];

	for (int i = 0; i < n; i++) num[i] = i;
	
	for (int i = 0; i < n; i++) {
		cout << "the " << i << "th entry of the arrray is = " << num[i] << endl;
	}

	delete[] num;

	for (int i = 0; i < n; i++) {
        cout << "the " << i << "th entry of the arrray is = " << num[i] << endl;
    }

	return 0; 
}

