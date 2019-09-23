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
	TritSet set2(20);

	std::cout << "set1.capacity() : " << set1.capacity() << std::endl;

	set1[1] = T;
	set1[3] = T;
	set1[4] = F;
	set1[5] = F;
	set1[2] = T;
	set1[6] = T;
	set1[7] = F;

	set2[1] = F;
	set2[3] = T;
	set2[4] = F;
	set2[6] = F;
	set2[7] = F;
	set2[10] = T;
	set2[17] = F;

	TritSet set3 = ~set1;

	for (int i = 0; i < set3.GetTritsAmount(); i++) {
		if (set3[i] == T) std::cout << set1[i] << " | " << set2[i] <<  " = " << "set3[" << i << "] = " << "T" << std::endl;
		else if (set3[i] == F) std::cout << set1[i] << " | " << set2[i] << " = " << "set3[" << i << "] = " << "F" << std::endl;
	}

	std::cout << "set3.capacity() : " << set3.capacity() << std::endl;
	std::cout << "set3.length() : " << set3.length() << std::endl;
	std::cout << "set3.countTrits(T) : " << set3.countTrits(T) << std::endl;
	std::cout << "set3.countTrits(F) : " << set3.countTrits(F) << std::endl;
	std::cout << "set3.countTrits(U) : " << set3.countTrits(U) << std::endl;

	std::cin;

	return 0;
}