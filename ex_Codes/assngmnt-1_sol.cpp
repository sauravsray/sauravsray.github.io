
#include<iostream>
#include<cassert>
#include<math.h>

using namespace std ;

// Matrix-Matrix Multiplication 
double** Multiply (const double** A, int m1, int n1, 
				   const double** B, int m2, int n2);

// scalar-Matrix Multiplication 
double** Multiply (const double** A, int m1, int n1, double c);

//p-norm 
double Norm(const double *vector, int size, int p = 2);

int main ()
{
	int multtype;
	int userentry = 0;
	
	cout << " This code performs various types of Matrix multiplications" << endl;
	cout << " Press " << endl;
	cout << "       1 and enter : Scalar X Matrix " << endl;
	cout << "       2 and enter : Matrix X Matrix " << endl;
	cout << "       3 and enter : Vector X Matrix " << endl;
	cout << "       4 and enter : Matrix X Vector " << endl;
	cin >> multtype; 
	cout << endl;

	cout << " Press " << endl;
	cout << "         1 : to enter matrix and vector or scalar entries " << endl;
	cout << "         0 : to choose default matrix and vector or scalar entries "
		<< endl;
	cin >> userentry;
	cout << endl;

	int m, n; // dimensions of matrix1, m rows, n columns 
	int k, l; // dimensions of matrix2, k rows, l columns

	switch (userentry){ 
		case 0: // for default matrices 
				// these are fixed values
			m = 2; n = 2;
			k = 2; l = 2;
			break;

		case 1: // this is for user entries 

			switch (multtype) {
				case 1: // Scalar X Matrix
					cout << " enter the no. of rows for matrix " << endl;
					cin >> m;
					cout << endl;
					cout << " enter the no. of columns for matrix " << endl;
					cin >> n;
					cout << endl;
					cout << "it comes here"<<endl;
					k = 0; l = 0; // some default values to be not used
					break;
				case 2: // Matrix X Matrix
					cout << " enter the no. of rows for matrix-1 " << endl;
					cin >> m;
					cout << endl;
					cout << " enter the no. of columns for matrix-1 " << endl;
					cin >> n;
					cout << endl;

					cout << " enter the no. of rows for matrix-2 " << endl;
					cin >> k;
					cout << endl;
					cout << " enter the no. of columns for matrix-2 " << endl;
					cin >> l;
					cout << endl;
					break;
					} // end of "switch (multtype) {".
			break;
	} // end of "switch (userentry){"

	// ideally all these should not be declared with every case for "multtype"
	// due to lack of use of macros we declare these even if not required.
	double** matrix1 = new double*[m];
    for (int i = 0; i < m ; i++) matrix1 [i] = new double [n];

	double** matrix2 = new double*[k];
    for (int i = 0; i < k ; i++) matrix2 [i] = new double [l];

	double c; // scalar for multiplication


	switch(userentry){
		case 0:						// just some choice for default
			switch (multtype) {
				case 1: // Scalar X Matrix
					// Matrix-1
					for (int i = 0; i < m ; i++){
                		for (int j = 0; j < n; j++){
                    		matrix1 [i][j] = i + j;
                		}
            		}

					c = 4.3;

					break;
				case 2: // Matrix X Matrix
					// Matrix-1
					for (int i = 0; i < m ; i++){
                		for (int j = 0; j < n; j++){
                    		matrix1 [i][j] = i + j;
                		}
            		}

					// Matrix-2
    				for (int i = 0; i < k ; i++){
        				for (int j = 0; j < l; j++){
            				matrix2 [i][j] = 2 * i + j;
						}
					}
					break;
			} // End of "switch (multtype) {".
			break;

		case 1:						// user entry
			switch (multtype) {
				case 1: // Scalar X Matrix
					// Enter Matrix-1
					for (int i = 0; i < m ; i++){
                		for (int j = 0; j < n; j++){
                    		cout << "enter the ("<< i + 1  << ","<< j + 1 
									<< ")th element of matrix-1" << endl;
                    		cin >> matrix1 [i][j];
						}
					}

					cout << " enter the scalar c " << endl;
					cin >> c;
					cout << endl;
					break;

				case 2: // Scalar X Matrix
					// Enter Matrix-1
					for (int i = 0; i < m ; i++){
               		 	for (int j = 0; j < n; j++){
                    		cout << "enter the ("<< i + 1  << ","<< j + 1 
									<< ")th element of matrix-1" << endl;
                    		cin >> matrix1 [i][j];
                		}
            		}
					// Enter Matrix-2
					for (int i = 0; i < k ; i++){
                		for (int j = 0; j < l; j++){
                    		cout << "enter the ("<< i + 1 << "," << j + 1 
									<< "th element of matrix-2" << endl;

                    		cin >> matrix2 [i][j];
                		}
					}
					break;
				}
				break;
			} // End of "switch(userentry){"


	cout << "matrix1 = " << endl;
	for (int i = 0; i < m ; i++){
		for (int j = 0; j < n; j++){
			cout << matrix1[i][j] << " ";
		} 
		cout << endl;
	}

	cout << endl;
	switch (multtype) {
		case 2: // Matrix X Matrix
			//Display matrix2

    		cout << "matrix2 = " << endl;
    		for (int i = 0; i < k ; i++){
        		for (int j = 0; j < l; j++){
            	cout << matrix2[i][j] << " ";
        		}
        		cout << endl;
    		}
    	cout << endl;
		break;
	}

	double** scalmul; 
	double** mulmat; 
	switch (multtype) {
		case 1: // Scalar X Matrix
			scalmul = Multiply ((const double **) matrix1, m, n, c);
			//Display scalmul 
			cout << "The matrix product = " << endl;
    		for (int i = 0; i < m; i++){
        		for (int j = 0; j < n; j++){
            		cout << scalmul [i][j] << " ";
        		}
        		cout << endl;
    		}
			break;
		case 2: // matrix1 X matrix2 is returned to mulmat
			mulmat = Multiply((const double **) matrix1, m, n, 
								(const double **) matrix2, k, l);

			//Display mulmat
			cout << "The matrix product = " << endl;
    		for (int i = 0; i < m; i++){
        		for (int j = 0; j < l; j++){
            		cout << mulmat [i][j] << " ";
        		}
        		cout << endl;
    		}
			break;
		}
    cout << endl;
	// Free dynamically allocated memory
    for (int i = 0; i < m ; i++) delete[] matrix1 [i];
	delete[] matrix1;
    for (int i = 0; i < k ; i++) delete[] matrix2 [i];
    delete[] matrix2;
	return 0;
}


// Matrix  X Matrix Multiplication definition

double** Multiply (const double** A, int m1, int n1, 
				   const double** B, int m2, int n2)
{

	assert (n1 == m2 && "Matrix Dimensions Incompatible");

	double** matrixm = new double*[m1];
    for (int i = 0; i < m1; i++){
        matrixm [i] = new double [n2];
		for (int j = 0; j < n2; j++){
			matrixm [i][j] = 0.0;
			for (int p = 0; p < n1; p++){
				matrixm [i][j] += A[i][p] * B[p][j];
			}
		}
	}

	return matrixm;
}

// scalar-Matrix Multiplication 
double** Multiply (const double** A, int m1, int n1, double c)
{
	double** matrixm = new double*[m1];
    for (int i = 0; i < m1; i++){
        matrixm [i] = new double [n1];
		for (int j = 0; j < n1; j++){
			matrixm [i][j] += A[i][j] * c;
		}
	}

	return matrixm;
}

