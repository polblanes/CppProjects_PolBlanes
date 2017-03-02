#include "DynArray.hh"
#include <stdlib.h>
#include <iostream>

void main() {
	DynArray daA;
	DynArray daB(8, 1);

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

	std::cout << ((daA == daB) ? "True" : "False") << std::endl;

	std::cout << "Assigning daB to daA..." << std::endl;
	daA = daB;

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

	std::cout << ((daA == daB) ? "True" : "False") << std::endl;

}