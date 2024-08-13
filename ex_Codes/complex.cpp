
#include <iostream>
#include <cmath>

using namespace std;

// via pointers
/*
void CalculateRealAndImaginary (double r, double theta, 
                                double* preal,
                                double* pImaginary);
*/
// via reference
void CalculateRealAndImaginary (double r, double theta,
                                double& real,
                                double& Imaginary);

int main ()
{
    double r = 3.4;
    double theta = 1.23;
    double x, y;

    //CalculateRealAndImaginary (r, theta, &x, &y); // for pointer
    CalculateRealAndImaginary (r, theta, x, y); // for reference
    cout << "Real part = " << x << endl;
    cout << "Imaginary part = " << y << endl;

    cout << "The complex number is " << x << " + i " << y << endl;
    return 0;
}

// For pointer
/*
void CalculateRealAndImaginary (double r, double theta, 
                                double* preal,
                                double* pImaginary)
{
    *preal = r * cos (theta);
    *pImaginary = r * sin (theta);
}
*/
// for reference

void CalculateRealAndImaginary (double r, double theta,
                                double& real,
                                double& Imaginary)
{
    real = r * cos (theta);
    Imaginary = r * sin (theta);
}

