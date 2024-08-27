
// stakaray.cpp
// a stack as a class

#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Stack
{ 
    private:
//        enum { MAX = 10 };      //(non-standard syntax)
        static const int MAX;	// not this why ?
        static const int MAX = 10;
        int st[MAX];            //stack: array of integers
        int top;                //number of top of stack
    public:
        Stack()                 //constructor
        { top = 0; }
        void push(int var)      //put number on stack
        { st[++top] = var; }    // st[top + 1] = var // and  top = top + 1
        int pop()               //take number off stack
        { return st[top--]; }   // st[top] removes this // and top = top -1
};
// int Stack::MAX = 10;  // not this though static ?? 
////////////////////////////////////////////////////////////////
int main()
{
    Stack s1;
    s1.push(11);
    s1.push(22);

    cout << "1: " << s1.pop() << endl;  //22
    cout << "2: " << s1.pop() << endl;  //11

    s1.push(33);
    s1.push(44);
    s1.push(55);
    s1.push(66);
    cout << "3: " << s1.pop() << endl;  //66
    cout << "4: " << s1.pop() << endl;  //55
    cout << "5: " << s1.pop() << endl;  //44
    cout << "6: " << s1.pop() << endl;  //33
    return 0;
}
