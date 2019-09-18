#pragma once
#include "TritSet.h"

// 00 - U
// 10 - F
// 11 - T

namespace tritsBits {

	int bpow(int pow);

	tritset::trit GetTrit(unsigned* src, int index);

}