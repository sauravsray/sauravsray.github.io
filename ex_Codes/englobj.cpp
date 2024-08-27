
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Distance
   {
   private:
      int feet;
      float inches;
   public:
//English Distance class
void setdist(int ft, float in)  //set Distance to args
   { feet = ft; inches = in; }
void getdist()              //get length from user
   {
   cout << "\nEnter feet: ";  cin >> feet;
   cout << "Enter inches: ";  cin >> inches;
   }
void showdist()             //display distance
   { cout << feet << "\'" << inches <<"\"" << endl; }
};
////////////////////////////////////////////////////////////////
int main()
{
    Distance dist1, dist2; //define two lengths
    dist1.setdist(11, 6.25); //set dist1
    dist2.getdist(); //get dist2 from user

                                  //display lengths
    cout << endl << "dist1 = ";  dist1.showdist();
    cout << endl << "dist2 = ";  dist2.showdist();
    cout << endl;
    return 0;
   }
