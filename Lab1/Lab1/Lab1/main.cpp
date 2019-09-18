#include "TritSet.h"
#include "TritsBits.h"
#include <iostream>

using namespace tritset;
using namespace tritsBits;

int main() {

	TritSet set1(49);

	TritSet set3 = set1;

	unsigned a = 502357;

	if(GetTrit(&a, 7) == F) std::cout << "F" << std::endl;
	else if (GetTrit(&a, 7) == T) std::cout << "T" << std::endl;
	else if (GetTrit(&a, 7) == U) std::cout << "U" << std::endl;


	return 0;
}