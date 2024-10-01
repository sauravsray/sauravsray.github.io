#include <iostream>
#include <assert.h>
using namespace std;

int no_of_digitis (int);
void print (int v, int b);

int main ()
{
	int v; 	// the decimal interger to be taken as a keyboard input
	cout << "Enter the interger v in decimal format" << endl;
	cin >> v;
	cout << endl;

	cout << "Enter the base b for conversion" << endl;
	int b;	// the base to which the deimal has to be converted
	cin >> b;
	cout << endl;

	print (v, b);
	return 0;
}

void print (int v, int b = 10)
{

	assert ((b >= 2 ) && (b <= 16) && 
					"the range of b should be between 2 and 16");
	//int numint = no_of_digitis (v);
	int numint = 4;
	int* base_b_express = new int [numint * 4];	// max no.of int required 

	int temp, res;
	temp = v;
	int i = 0;
	while (temp >= b)
		{
			res = temp % b;
			base_b_express [i] = res;
			temp = (temp - res) / b;
			i++;
		}
		base_b_express [i] = temp;
	cout << "The interger " << v << " in base " << b << " is = " << endl;
	for (int j = i; j >= 0; j--)
		{
			cout << base_b_express [j] ;
		}
	cout << endl;
}

