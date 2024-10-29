
#include <iostream>
#include "DoubleVector.hpp"

int main()
{
	DoubleVector<5> v;

	v[0] = 1.0; 		// this is okay 
//	v[7] = 5.0;			// will trip the assertion 

	return 0;
}
	

