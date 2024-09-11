
// arrover2.cpp
// creates safe array (index values are checked before access)
// uses one access() function for both put and get
#include <iostream>
using namespace std;

const int LIMIT = 100;          //array size
////////////////////////////////////////////////////////////////
class safearay
{ 
    private:
        int arr[LIMIT];
    public:
        int& access(int n)          //note: return by reference
        {
            if( n< 0 || n>=LIMIT )
            { cout << "\nIndex out of bounds"; exit(1); }
            return arr[n];
        } 
};

////////////////////////////////////////////////////////////////
int main()
{
//    int otherarray[100];                // lets say i have hand 
                                        // specified all its values. 
    safearay sa1;

    for(int j = 0; j < LIMIT; j++)          //insert elements
        sa1.access(j) = j * 10;

    for(int j = 0; j < LIMIT; j++)              //display elements
    {
        int temp = sa1.access(j); //*right* side of equal sign
        cout << "Element " << j << " is " << temp << endl;
    }
    return 0; 
}
