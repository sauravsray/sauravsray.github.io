
// counten.cpp
// inheritance with Counter class
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Counter						//base class
{ 
    protected:						//NOTE: not private
	//private:
        unsigned int count;         //count
    public:
        Counter() : count(0) {}     //constructor  no args

        Counter(int c) : count(c)   //constructor, one arg 
        {}

        unsigned int get_count()    //return count
        { return count; }

        Counter operator ++ ()      //increment count
        {
            ++count;                //  increment count, then return
            return Counter(count);  //  an unnamed temporary object
        }                           //  initialized to this count
};

////////////////////////////////////////////////////////////////

class CountDn : public Counter		//derived class
{
	public:
      	Counter operator -- ()		//decr count (prefix)
         	{ return Counter(--count); }
};

////////////////////////////////////////////////////////////////
int main() 
{
	CountDn c1(2);							//c1 of class CountDn

	cout << "\nc1=" << c1.get_count();	//display c1
	
	++c1; ++c1; ++c1;					//increment c1, 3 times
	cout << "\nc1=" << c1.get_count();	//display it

	--c1; --c1;							//decrement c1, twice
	cout << "\nc1=" << c1.get_count();	//display it
	cout << endl;

	Counter c2;
	++c2;

	//--c2;								//compiler will throw out an error

	return 0;
}



