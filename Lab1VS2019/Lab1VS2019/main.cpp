#include "TritsBits.h"
#include "TritSet.h"

int main() {

	tritset::TritSet set(1000);
	tritset::TritSet set1(1000);

	unsigned defaultCapacity = set.capacity();

	set[10'000] = tritsBits::trit::T;

	set[10'000] = tritsBits::trit::U;

	tritset::TritSet set2 = set1 & set;

	set = set2;

	set.shrink();

	return 0;
}