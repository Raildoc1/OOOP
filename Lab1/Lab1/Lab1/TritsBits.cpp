#include "TritsBits.h"

namespace tritsBits {

	unsigned bpow(unsigned pow) {

		unsigned result = 1;

		for (unsigned i = 0; i < pow; i++) {
			result *= 2;
		}

		return result;
	}

	trit GetTrit(unsigned * src, unsigned index) {

		int bitMask = bpow((sizeof(unsigned) * 8 - 1) - (index * 2));

		if ((bitMask & (*src)) == 0) return U;

		bitMask = bpow((sizeof(unsigned) * 8 - 1) - (index * 2 + 1));

		if ((bitMask & (*src)) == 0) return F;

		return T;
	}

	void SetTrit(unsigned * src, unsigned index, trit trit) {

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

	trit AndOperation(trit a, trit b) {
		if (a == F || b == F) return F;
		else if (a == T && b == T) return T;
		else return U;
	}

	trit OrOperation(trit a, trit b) {
		if (a == T || b == T) return T;
		else if (a == F && b == F) return F;
		else return U;
	}

	trit NotOperation(trit a) {
		if (a == T) return F;
		if (a == F) return T;
		if (a == U) return U;
	}

}