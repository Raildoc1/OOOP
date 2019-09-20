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

	void TritSet::ExpandMemory(int index) {
	
		if (index > currentTritsAmount) currentTritsAmount = index;

		if ((index / (sizeof(unsigned) * 4)) >= currentArraySize) {

			int newArraySize = std::ceil((index + 1) * 2 / (float)8 / (float)sizeof(unsigned));

			// My own realloc
			unsigned * temp = new unsigned[newArraySize];

			for (int i = 0; i < currentArraySize; i++) {
				temp[i] = memory[i];
			}

			delete[] memory;
			memory = temp;

			currentArraySize = newArraySize;

		}

	}

	void TritSet::SetTrit(int index, tritsBits::trit trit) {
	
		tritsBits::SetTrit(&memory[index / (sizeof(unsigned) * 4)], index % (sizeof(unsigned) * 4), trit);

	}

	TritSet::TritSet(int size) : defaultTritsAmount(size), currentTritsAmount(size)  {
	
		defaultArraySize = std::ceil(size * 2 / (float)8 / (float)sizeof(unsigned));

		currentArraySize = defaultArraySize;

		memory = new unsigned[defaultArraySize];

		memset(memory, 0, defaultArraySize * sizeof(unsigned));
	}

	TritSet::TritSet(TritSet & tritSet) {

		defaultArraySize = tritSet.currentArraySize;
		CopyUnsignedArray(tritSet.memory, &memory, tritSet.currentArraySize);
		
	}

	TritSet::~TritSet() {
		delete [] memory;
	}

	TritSet::Ref TritSet::operator[](const unsigned index) {

		if (index >= currentTritsAmount) {

			unsigned * newCell = new unsigned(0);

			TritSet::OutBoundsRef * Ref = new TritSet::OutBoundsRef(newCell, index % (sizeof(unsigned) * 4), index, this);

			return * Ref;

		} else {

			TritSet::Ref * Ref = new TritSet::Ref(&memory[index / (sizeof(unsigned) * 4)], index % (sizeof(unsigned) * 4));

			return * Ref;

		}

	}

	tritsBits::trit TritSet::operator[](const unsigned index) const {

		tritsBits::trit temp = tritsBits::GetTrit(&memory[index / (sizeof(unsigned) * 4)], index % (sizeof(unsigned) * 4));

		return temp;

	}
	

}
