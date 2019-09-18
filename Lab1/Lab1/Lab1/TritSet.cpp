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

}
