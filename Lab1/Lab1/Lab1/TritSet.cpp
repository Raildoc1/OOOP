#include "TritSet.h"
#include <iostream>

namespace tritset {

	// MY OWN MEMCPY FUNCTION (only for unsigned :c)
	void TritSet::CopyUnsignedArray(const unsigned * source, unsigned ** target, unsigned size) {
		
		*target = new unsigned[size];

		for (int i = 0; i < size; i++) {
			(*target)[i] = source[i];
		}
	}

	TritSet::TritSet(int size) : TritsAmount(size)  {
	
		ArraySize = std::ceil(size * 2 / (float)8 / (float)sizeof(unsigned));

		std::cout << "size = " << ArraySize << std::endl;

		memory = new unsigned[ArraySize];

	}

	TritSet::TritSet(TritSet & tritSet) {

		ArraySize = tritSet.ArraySize;
		CopyUnsignedArray(tritSet.memory, &memory, tritSet.ArraySize);
		
	}

	TritSet::~TritSet() {
		delete [] memory;
	}

}
