#pragma once

// 00 - U
// 10 - F
// 11 - T

namespace tritsBits {

	enum trit { T, F, U };

	unsigned bpow(unsigned pow);

	trit GetTrit(unsigned* src, unsigned index);
	void SetTrit(unsigned* src, unsigned index, trit trit);

	trit AndOperation(trit a, trit b);
	trit OrOperation(trit a, trit b);
	trit NotOperation(trit a);
}