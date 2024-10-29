
#include <iostream>
#include <cassert>

#include <fstream>	// This for file input output

using namespace std;

int main ()
{
	double x[3] = {0.0, 1.0, 0.0};
	double y[3] = {0.0, 0.0, 1.0};

	// write_output is a variable of type "ofstream"
	ofstream write_output ("output.dat"); 	// output.dat is the file
						// which will be used to store 
	
	// check if the file is open or not
	assert (write_output.is_open());
	for (int i = 0; i < 3; i++) {
		write_output << x[i] << " " << y[i] << "\n";
	}
	write_output.close (); 	// close the file "output.dat"
	return 0;
	
}
