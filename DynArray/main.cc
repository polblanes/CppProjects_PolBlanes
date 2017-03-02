#include "DynArray.hh"
#include <stdlib.h>
#include <iostream>

void main() {
	DynArray daA;
	DynArray daB(8, 1);

	std::cout << "daA: ";
	for (int i = 0; i < 8; i++) {
		std::cout << daA[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "daB: ";
	for (int i = 0; i < 8; i++) {
		std::cout << daB[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Comparing daA with daB: daA == daB" << std::endl;

	std::cout << (daA == daB) << std::endl;

	std::cout << "Filling daA with ones..." << std::endl;
	//daA.fill(&daA[0], &daA[8], 1);
	std::cout << "daA: ";
	for (int* p = daA.begin(); p < daA.end(); p++) {
		std::cout << *p << " ";
	}
	std::cout << std::endl;
	std::cout << "daB: ";
	for (int* p = daB.begin(); p < daB.end(); p++) {
		std::cout << *p << " ";
	}
	std::cout << std::endl;

	std::cout << "Comparing daA with daB: daA == daB" << std::endl;

	std::cout << (daA == daB) << std::endl;

}