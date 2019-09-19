#include "TritSet.h"
#include "TritsBits.h"
#include <iostream>

using namespace tritset;
using namespace tritsBits;

int main() {

	TritSet set1(49);

	SetTrit(set1.memory, 4, T);

	set1[4] = F;

	if ((set1[4] == F) == false) {
		std::cout << "set1[4] == F"<< std::endl;
	}

	return 0;
}