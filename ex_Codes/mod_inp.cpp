
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	double x[100], y[100];
 	ifstream read_file("output.dat");
 	assert(read_file.is_open());
	
	int i = 0;
	while (!read_file.eof())
	{
		read_file >> x[i] >> y[i];
		i++; 
	}
  	read_file.close();
	return 0; 
}


