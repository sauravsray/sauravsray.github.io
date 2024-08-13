
#include <iostream>
#include <cmath>

using namespace std;

// Static allocation code
void DoSomething (double u[], double A[][],
                double B[10][10]);

int main ()
{
    // Static memory allocation
    double u[5], A[10][10], B[10][10];

    DoSomething (u, A, B);

    // This will print the values allocated in 
    // the function DoSomething

    cout << u[2] << endl;
    cout << A[2][3] << endl;
    cout << B[3][3] << endl;

    return 0;
}

void DoSomething (double u[], double A[][],
                double B[10][10])
{
    u[2] = 1.0;
    A[2][3] = 4.0;
    B[3][3] = -90.6;
    return;
}


/*
void DoSomething (double* u, double** A);

int main ()
{
    // dynamic memory allocation
    double* u = new double [10];
    double** A = new double* [10];

    for (int i = 0; i < 10; i++) 
    {
        A[i] = new double [10];
    }
    DoSomething (u, A);

    // This will print the values allocated in
    // the function DoSomething

    cout << u[2] << endl;
    cout << A[2][3] << endl;

    delete[] u;
    for (int i = 0; i < 10; i++)
    {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}


void DoSomething (double* u, double** A)
{
    u[2] = 1.0;
    A[2][3] = 4.0;
    return;
}

*/
