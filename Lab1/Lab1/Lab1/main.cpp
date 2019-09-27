#include "TritSet.h"
#include "TritsBits.h"
#include <iostream>

//0 - T
//1 - F
//2 - U

using namespace tritset;
using namespace tritsBits;

int main() {

	TritSet set1(100);

	std::cout << "set1.capacity() : " << set1.capacity() << std::endl;

	set1[1] = T;
	set1[3] = T;
	set1[83] = T;
	set1[5] = T;
	set1[17] = T;
	set1[18] = T;
	set1[7] = T;
	set1[43] = T;
	set1[58] = T;
	set1[96] = T;
	set1[32] = T;

	for (int i = 0; i < set1.GetTritsAmount(); i++) {
		std::cout << "set[" << i << "] = "<< set1[i] << std::endl;
	}

	set1.trim(32);

	for (int i = 0; i < set1.GetTritsAmount(); i++) {
		std::cout << "set[" << i << "] = " << set1[i] << std::endl;
	}

	std::cout << "set3.capacity() : " << set1.capacity() << std::endl;
	std::cout << "set3.length() : " << set1.length() << std::endl;
	std::cout << "set3.countTrits(T) : " << set1.countTrits(T) << std::endl;
	std::cout << "set3.countTrits(F) : " << set1.countTrits(F) << std::endl;
	std::cout << "set3.countTrits(U) : " << set1.countTrits(U) << std::endl;
	std::cout << std::endl << std::endl;

	std::unordered_map<tritsBits::trit, int> newMap = set1.cardinality();

	for (auto & x : newMap) {
		std::cout << x.first << " " << x.second << std::endl;
	}

	std::cin;

	return 0;
}