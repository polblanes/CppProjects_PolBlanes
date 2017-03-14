#include "DynArray.hh"
#include <stdlib.h>
#include <iostream>

void main() {
	DynArray daA(8, 1);

	std::cout << "daA: ";
	for (int* p = daA.begin(); p < daA.end(); p++) {
		std::cout << *p << " ";
	}
	std::cout << std::endl;

	daA.push(2);
	
	std::cout << "Pushed a 2 onto daA" << std::endl << "daA: ";
	for (int* p = daA.begin(); p < daA.end(); p++) {
		std::cout << *p << " ";
	}
	std::cout << std::endl;

	daA.pop();

	std::cout << "Popped daA" << std::endl << "daA: ";
	for (int* p = daA.begin(); p < daA.end(); p++) {
		std::cout << *p << " ";
	}
	std::cout << std::endl;
	std::cout << daA.capacity() << std::endl;

	daA.erase(2);

	std::cout << "Erased 3rd value of daA" << std::endl << "daA: ";
	for (int* p = daA.begin(); p < daA.end(); p++) {
		std::cout << *p << " ";
	}
	std::cout << std::endl;
	
}
