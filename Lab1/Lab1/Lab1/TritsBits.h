#pragma once

// 00 - U
// 10 - F
// 11 - T

namespace tritsBits {

	enum trit { T, F, U };

	int bpow(int pow);

	trit GetTrit(unsigned* src, int index);
	void SetTrit(unsigned* src, int index, trit trit);

}