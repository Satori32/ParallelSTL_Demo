#include <iostream>
#include <random>
#include <vector>
#include <execution>
#include <algorithm>

#include "StopWatch_II.h"

typedef std::vector<std::uint64_t> DType;

DType MakeVector(std::size_t L, unsigned int S=0) {
	std::mt19937 mt(S);
	DType R;
	for(std::size_t i = 0; i < L; i++) {
		R.push_back(mt());
	}

	return R;
}
int main() {
	DType A = MakeVector(10000000);
	DType B = A;
	StopWatch SW;

	std::cout << "01 Start!" << std::endl;
	SW.ReStart();
	std::sort(std::execution::seq, B.begin(), B.end());
	std::cout << "01 End! "<<SW.Ellipse().count() << std::endl;
	
	B = A;
	std::cout << "02 Start!" << std::endl;
	SW.ReStart();
	std::sort(std::execution::par, B.begin(), B.end());
	std::cout << "02 End! " <<SW.Ellipse().count() << std::endl;
	B = A;
	std::cout << "03 Start!" << std::endl;
	SW.ReStart();
	std::sort(std::execution::par_unseq, B.begin(), B.end());
	std::cout << "03 End! " <<SW.Ellipse().count() << std::endl;
}