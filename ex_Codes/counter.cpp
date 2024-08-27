
// counter.cpp
// object represents a counter variable
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Counter
{ 
    private:
    unsigned int count;  //count
    public:
      Counter() : count (0) 
        { cout << " I’m the constructor " << endl ; }
              //constructor
//      { count = 0; }
    void inc_count()  //increment count
      { count++; }
    int get_count()   //return count
      { return count; }
};

////////////////////////////////////////////////////////////////
int main()
{
    Counter c1, c2;                     //define and initialize
    cout << "\n c1 = " << c1.get_count();  //display
    cout << "\n c2 = " << c2.get_count();

    c1.inc_count(); //increment c1
    c2.inc_count(); //increment c2
    c2.inc_count(); //increment c2

    cout << "\n c1 = " << c1.get_count();  //display again
    cout << "\n c2 = " << c2.get_count();
    cout << endl;
    return 0;
}

