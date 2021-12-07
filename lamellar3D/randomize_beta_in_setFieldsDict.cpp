#include <iostream>
#include <random>
#include <fstream>
using namespace std;

constexpr int MIN = 0;
constexpr int MAX = 39;

constexpr int RAND_NUMS_TO_GENERATE = 20;

int main()
{
	random_device rd;
	default_random_engine eng(rd());
	uniform_int_distribution<int> distr(MIN, MAX);

	ofstream outpf;
	outpf.open ("outp.dat"); //opening output file

	if (!outpf) {
		cout << "No such output file" << endl;
	}
	else {
		cout << "Printing coordinates" << endl;
		for (int i = MIN; i <= MAX; ++i)
		{
			for (int n = 0; n < RAND_NUMS_TO_GENERATE; ++n) {
			int j = distr(eng);
			outpf << "	boxToCell { box (-6 $y_" << i << " $z_" << j << ") (64 $y_" << i+1 << " $z_" << j+1 << "); fieldValues (" << endl;
			outpf << "	volScalarFieldValue phi_alpha 0.0" << endl;
			outpf << "	volScalarFieldValue phi_beta 1.0 ); }" << endl; //printed in setFieldsDict format
			}
		}
	}
	outpf.close();

	return 0;
}