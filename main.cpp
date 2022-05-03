#include <iostream>
#include <string>
#include <vector>

#include "Matrix.hpp"

using namespace std;
using namespace zich;

int main(){

	vector<double> vals1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
    Matrix mat1(vals1, 4, 3);
    vector<double> vals2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Matrix mat2(vals2, 3, 4);
   
	cout << mat1 << endl << " * " << endl << mat1 << endl << " = " << endl;

	cout << mat1 * mat2 << endl;


}