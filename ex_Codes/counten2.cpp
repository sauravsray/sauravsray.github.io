
// counten2.cpp
// inheritance with Counter class
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Counter						//base class
{ 
    protected:						//NOTE: not private
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
		CountDn() : Counter()		//constructor, no args 
			{}

		CountDn(int c) : Counter(c) //constructor, 1 arg
			{}

      	Counter operator -- ()		//decr count (prefix)
         	{ return Counter(--count); }
};

////////////////////////////////////////////////////////////////
int main() 
{
	CountDn c1;							//c1 of class CountDn
	CountDn c2(100);

	cout << "\nc1=" << c1.get_count();	//display c1
	cout << "\nc2=" << c2.get_count();	//display c2
	
	++c1; ++c1; ++c1;					//increment c1, 3 times
	cout << "\nc1=" << c1.get_count();	//display it

	--c2; --c2;							//decrement c1, twice
	cout << "\nc2=" << c2.get_count();	//display it

//	CountDn c3 = --c2;					//create c3 from c2
//	cout << "\nc3=" << c3.get_count();	//display c3
	cout << endl;
	return 0;
}



