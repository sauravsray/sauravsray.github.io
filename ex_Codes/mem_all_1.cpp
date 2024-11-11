
#include <iostream>
#include <exception>	//	include this to catch exception bad_alloc”

using namespace std;

int main()
{
	cout << "Enter number of integers you wish to reserve: ";
	try
	{
		int input = 0;
		cin >> input;

		// Request memory space and then return it
		int* numArray = new int [input];
		delete[] numArray;
	}
	catch (bad_alloc& exp)
	{
		cout << "Exception encountered: " << exp.what() << endl;
		cout << "Got to end, sorry!" << endl;
	}
	catch (...)
	{
		cout << "Exception occurred. Got to end, sorry!" << endl;
	}
	return 0;
}
