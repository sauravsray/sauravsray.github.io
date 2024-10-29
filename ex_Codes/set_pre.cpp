
#include <iostream>
#include <fstream>

int main( )
{
	double x = 1.8364238;
	std::ofstream write_output("Output.dat");
	
	write_output.precision(3); // 3 sig figs
	write_output << x << "\n";

	write_output.precision(5); // 5 sig figs
	write_output << x << "\n";

	write_output.precision(10); // 10 sig figs
	write_output << x << "\n";
	write_output.close();

	return 0;
}


