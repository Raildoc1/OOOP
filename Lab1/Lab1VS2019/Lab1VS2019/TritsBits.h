#pragma once

#include <iostream>

// 00 - U
// 10 - F
// 11 - T

namespace tritsBits {

	enum class trit : int {
		T = 1,
		F = -1,
		U = 0
	};

	unsigned bpow(unsigned pow);

	trit GetTrit(unsigned* src, unsigned index);
	void SetTrit(unsigned* src, unsigned index, trit trit);

	trit operator &(trit a, trit b);
	trit operator |(trit a, trit b);
	trit operator ~(trit a);
	std::ostream& operator << (std::ostream& cout, trit trit);
}