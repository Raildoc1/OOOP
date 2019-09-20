#include "TritSet.h"
#include "TritsBits.h"
#include <iostream>

//0 - T
//1 - F
//2 - U

using namespace tritset;
using namespace tritsBits;

int main() {

	TritSet set1(5);

	set1[1000] = F;

	std::cout << set1[1000] << std::endl;

	return 0;
}