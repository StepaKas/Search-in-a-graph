#include "matice.h"



int main(void)
{	
	
	
	Matrix A;
	A.scan_file("TextFile1.txt");
	cout << "Pocet kontinentu je " << A.get_num_of_continents() << endl;

	Matrix B;
	B.scan_file("TextFile2.txt");
	cout << "Pocet kontinentu je " << B.get_num_of_continents() << endl;

	Matrix C;
	C.scan_file("TextFile3.txt");
	cout << "Pocet kontinentu je " << C.get_num_of_continents() << endl;
	
	


	return 0;
}
