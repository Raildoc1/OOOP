#include "TritsBits.h"
#include "TritSet.h"

int main() {

	tritset::TritSet set(1000);
	tritset::TritSet set1(1000);

	unsigned defaultCapacity = set.capacity();

	set[10'000] = tritsBits::trit::T;

	set[10'000] = tritsBits::trit::U;

	tritset::TritSet set2 = set1 & set;

	for (int i = 0; i < 100; i++) {
		std::cout << "set2[" << i << "] = " << set2[i] << std::endl;
	}

	set = set2;

	set.shrink();

	return 0;
}