#include "TritsBits.h"

namespace tritsBits {

	int bpow(int pow) {

		int result = 1;

		for (int i = 0; i < pow; i++) {
			result *= 2;
		}

		return result;
	}

	trit GetTrit(unsigned * src, int index) {

		int bitMask = bpow((sizeof(unsigned) * 8 - 1) - (index * 2));

		if ((bitMask & (*src)) == 0) return U;

		bitMask = bpow((sizeof(unsigned) * 8 - 1) - (index * 2 + 1));

		if ((bitMask & (*src)) == 0) return F;

		return T;
	}

	void SetTrit(unsigned * src, int index, trit trit) {

		if (trit == U) {

			unsigned bitMask1 = ~(bpow((sizeof(unsigned) * 8 - 1) - (index * 2)));
			unsigned bitMask2 = ~bpow((sizeof(unsigned) * 8 - 1) - (index * 2 + 1));

			(*src) &= bitMask1;
			(*src) &= bitMask2;

		} else if (trit == F) {

			unsigned bitMask1 = bpow((sizeof(unsigned) * 8 - 1) - (index * 2));
			unsigned bitMask2 = ~bpow((sizeof(unsigned) * 8 - 1) - (index * 2 + 1));

			(*src) |= bitMask1;
			(*src) &= bitMask2;

		} else {

			unsigned bitMask1 = bpow((sizeof(unsigned) * 8 - 1) - (index * 2));
			unsigned bitMask2 = bpow((sizeof(unsigned) * 8 - 1) - (index * 2 + 1));

			(*src) |= bitMask1;
			(*src) |= bitMask2;

		}

	}

}