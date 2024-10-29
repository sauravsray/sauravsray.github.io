
#include <cassert>
#include <iostream>
#include <fstream>

int main()
{
	double x[3], y[3];
	std::ifstream read_file("output.dat");
	assert(read_file.is_open());

	for (int i=0; i<3; i++)
	{
		read_file >> x[i] >> y[i];
	}

	read_file.close();
	return 0;
}

