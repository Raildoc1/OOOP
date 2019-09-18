#include "TritsBits.h"

namespace tritsBits {

	int bpow(int pow) {

		int result = 1;

		for (int i = 0; i < pow; i++) {
			result *= 2;
		}

		return result;
	}

	tritset::trit GetTrit(unsigned * src, int index) {

		int bitMask = bpow((sizeof(unsigned) * 8 - 1) - (index * 2));

		if ((bitMask & (*src)) == 0) return tritset::U;

		bitMask = bpow((sizeof(unsigned) * 8 - 1) - (index * 2 + 1));

		if ((bitMask & (*src)) == 0) return tritset::F;

		return tritset::T;
	}

}