#include "TritSet.h"
#include <iostream>
#include <cstring>

namespace tritset {

	// MY OWN MEMCPY FUNCTION (only for unsigned :c)
	void CopyUnsignedArray(const unsigned * source, unsigned ** target, unsigned size) {
		
		*target = new unsigned[size];

		for (int i = 0; i < size; i++) {
			(*target)[i] = source[i];
		}
	}

	TritSet::TritSet(int size) : TritsAmount(size)  {
	
		ArraySize = std::ceil(size * 2 / (float)8 / (float)sizeof(unsigned));

		std::cout << "size = " << ArraySize << std::endl;

		memory = new unsigned[ArraySize];

		memset(memory, 0, ArraySize * sizeof(unsigned));
	}

	TritSet::TritSet(TritSet & tritSet) {

		ArraySize = tritSet.ArraySize;
		CopyUnsignedArray(tritSet.memory, &memory, tritSet.ArraySize);
		
	}

	TritSet::~TritSet() {
		delete [] memory;
	}

	/*tritsBits::trit TritSet::operator[](const unsigned index) const {

		tritsBits::trit temp = tritsBits::GetTrit(&memory[index / (sizeof(unsigned) * 4)], index % (sizeof(unsigned) * 4));

		if (temp == tritsBits::T) {
			return tritsBits::T;
		} else if (temp == tritsBits::F) {
			return tritsBits::F;
		}

		return tritsBits::U;

	}*/

	TritSet::ref TritSet::operator[](unsigned index) {

		TritSet::ref * ref = new TritSet::ref(&memory[index / (sizeof(unsigned) * 4)], index % (sizeof(unsigned) * 4));

		return *ref;

	}

	

}
