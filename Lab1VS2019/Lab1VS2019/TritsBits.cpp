#pragma once

#include "TritsBits.h"

namespace tritsBits {

	unsigned bpow(unsigned pow) {

		unsigned result = 1;

		for (unsigned i = 0; i < pow; i++) {
			result *= 2;
		}

		return result;
	}

	trit GetTrit(unsigned* src, unsigned index) {

		int bitMask = bpow((sizeof(unsigned) * 8 - 1) - (index * 2));

		if ((bitMask & (*src)) == 0) return tritsBits::trit::U;

		bitMask = bpow((sizeof(unsigned) * 8 - 1) - (index * 2 + 1));

		if ((bitMask & (*src)) == 0) return tritsBits::trit::F;

		return tritsBits::trit::T;
	}

	void SetTrit(unsigned* src, unsigned index, trit trit) {

		if (trit == tritsBits::trit::U) {

			unsigned bitMask1 = ~(bpow((sizeof(unsigned) * 8 - 1) - (index * 2)));
			unsigned bitMask2 = ~bpow((sizeof(unsigned) * 8 - 1) - (index * 2 + 1));

			(*src) &= bitMask1;
			(*src) &= bitMask2;

		}
		else if (trit == tritsBits::trit::F) {

			unsigned bitMask1 = bpow((sizeof(unsigned) * 8 - 1) - (index * 2));
			unsigned bitMask2 = ~bpow((sizeof(unsigned) * 8 - 1) - (index * 2 + 1));

			(*src) |= bitMask1;
			(*src) &= bitMask2;

		}
		else {

			unsigned bitMask1 = bpow((sizeof(unsigned) * 8 - 1) - (index * 2));
			unsigned bitMask2 = bpow((sizeof(unsigned) * 8 - 1) - (index * 2 + 1));

			(*src) |= bitMask1;
			(*src) |= bitMask2;

		}

	}

	trit AndOperation(trit a, trit b) {
		if (a == tritsBits::trit::F || b == tritsBits::trit::F) return tritsBits::trit::F;
		else if (a == tritsBits::trit::T && b == tritsBits::trit::T) return tritsBits::trit::T;
		return tritsBits::trit::U;
	}

	trit OrOperation(trit a, trit b) {
		if (a == tritsBits::trit::T || b == tritsBits::trit::T) return tritsBits::trit::T;
		else if (a == tritsBits::trit::F && b == tritsBits::trit::F) return tritsBits::trit::F;
		return tritsBits::trit::U;
	}

	trit NotOperation(trit a) {
		if (a == tritsBits::trit::T) return tritsBits::trit::F;
		if (a == tritsBits::trit::F) return tritsBits::trit::T;
		return tritsBits::trit::U;
	}

}