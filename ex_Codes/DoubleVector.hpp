
#include <cassert>

template<unsigned int DIM> 
class DoubleVector
{
	private:
		double mData[DIM];

	public:
		double& operator[](int index) // overloading the []  operator
		{
			assert(index < DIM); 
			assert(index > -1); 
			return(mData[index]);
		} 
};
		
