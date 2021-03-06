#pragma once

#include "TritSet.h"
#include <iostream>
#include <cstring>

namespace tritset {

	// MY OWN MEMCPY FUNCTION (only for unsigned :c)
	void CopyUnsignedArray(const unsigned* source, unsigned** target, unsigned size) {

		*target = new unsigned[size];

		for (unsigned i = 0; i < size; i++) {
			(*target)[i] = source[i];
		}
	}

	void TritSet::ExpandMemory(unsigned index) {

		if (index >= currentTritsAmount) currentTritsAmount = index + 1;

		if ((index / (sizeof(unsigned) * 4)) >= currentArraySize) {

			unsigned newArraySize = (unsigned)std::ceil((index + 1) * 2 / (float)8 / (float)sizeof(unsigned));

			// My own realloc
			unsigned* temp = new unsigned[newArraySize];

			for (unsigned i = 0; i < newArraySize; i++) {
				if (i < currentArraySize) temp[i] = memory[i];
				else temp[i] = 0;
			}

			delete[] memory;
			memory = temp;

			currentArraySize = newArraySize;

		}

	}

	void TritSet::ReduceMemory(unsigned lastValidTritIndex) {

		if (lastValidTritIndex <= currentTritsAmount) currentTritsAmount = lastValidTritIndex + 1;

		if ((lastValidTritIndex / (sizeof(unsigned) * 4)) <= currentArraySize) {

			unsigned newArraySize = (unsigned)std::ceil((lastValidTritIndex + 1) * 2 / (float)8 / (float)sizeof(unsigned));

			// My own realloc
			unsigned* temp = new unsigned[newArraySize];

			for (unsigned i = 0; i < newArraySize; i++) {
				temp[i] = memory[i];
			}

			delete[] memory;
			memory = temp;

			currentArraySize = newArraySize;
		}
	}

	void TritSet::SetTrit(unsigned index, tritsBits::trit trit) {

		if (index >= currentTritsAmount) {
			if (trit == tritsBits::trit::U) return;
			ExpandMemory(index);
		} 

		tritsBits::SetTrit(&memory[index / (sizeof(unsigned) * 4)], index % (sizeof(unsigned) * 4), trit);

	}

	tritsBits::trit TritSet::GetTrit(unsigned index) {

		if (index >= currentTritsAmount) return tritsBits::trit::U;
		return tritsBits::GetTrit(&memory[index / (sizeof(unsigned) * 4)], index % (sizeof(unsigned) * 4));
	}

	TritSet::TritSet(unsigned size) : defaultTritsAmount(size), currentTritsAmount(size) {

		defaultArraySize = (unsigned)std::ceil(size * 2.0 / 8.0 / (double)sizeof(unsigned));
		currentArraySize = defaultArraySize;

		memory = new unsigned[defaultArraySize];

		memset(memory, 0, defaultArraySize * sizeof(unsigned));
	}

	TritSet::TritSet(TritSet& tritSet) {
		defaultArraySize = tritSet.currentArraySize;
		currentArraySize = tritSet.currentArraySize;
		defaultTritsAmount = tritSet.currentTritsAmount;
		currentTritsAmount = tritSet.currentTritsAmount;

		CopyUnsignedArray(tritSet.memory, &memory, tritSet.currentArraySize);

	}

	TritSet::~TritSet() {
		delete[] memory;
	}

	void TritSet::shrink() {

		if (currentTritsAmount > defaultTritsAmount) {

			unsigned lastValidTrit = currentTritsAmount - 1;

			for (unsigned i = currentTritsAmount - 1; i >= defaultTritsAmount; i--) {
				if (GetTrit(i) == tritsBits::trit::U) {
					lastValidTrit--;
				}
				else {
					break;
				}
			}

			if (lastValidTrit < currentTritsAmount - 1) {
				ReduceMemory(lastValidTrit);
			}
		}

	}

	TritSet::Ref TritSet::operator[](const unsigned index) {
			return TritSet::Ref(index, this);
	}

	tritsBits::trit TritSet::operator[](const unsigned index) const {

		tritsBits::trit temp = tritsBits::GetTrit(&memory[index / (sizeof(unsigned) * 4)], index % (sizeof(unsigned) * 4));

		return temp;

	}

	TritSet TritSet::operator&(TritSet tritSet) {

		unsigned newSetSize = tritSet.currentTritsAmount > currentTritsAmount ? tritSet.currentTritsAmount : currentTritsAmount;

		TritSet newSet(newSetSize);

		for (unsigned i = 0; i < newSetSize; i++) {
			newSet[i] = tritSet[i]&GetTrit(i);
			//std::cout << "newSet[" << i << "] = " << tritsBits::AndOperation(tritSet[i], GetTrit(i)) << std::endl;
		}

		return newSet;
	}

	TritSet TritSet::operator|(TritSet tritSet) {

		unsigned newSetSize = tritSet.currentTritsAmount > currentTritsAmount ? tritSet.currentTritsAmount : currentTritsAmount;

		TritSet newSet(newSetSize);

		for (unsigned i = 0; i < newSetSize; i++) {
			newSet[i] = tritSet[i] | GetTrit(i);
		}

		return newSet;
	}

	TritSet TritSet::operator~() {

		TritSet newSet(currentTritsAmount);

		for (unsigned i = 0; i < currentTritsAmount; i++) {
			newSet[i] = ~GetTrit(i);
		}

		return newSet;
	}

	TritSet& TritSet::operator=(const TritSet &obj) {

		delete[] memory;

		currentArraySize = obj.currentArraySize;
		currentTritsAmount = obj.currentTritsAmount;
		defaultArraySize = obj.defaultArraySize;
		defaultTritsAmount = obj.defaultTritsAmount;

		memory = new unsigned[currentArraySize];
		CopyUnsignedArray(obj.memory, &memory, currentArraySize);

		return *this;
	}

	TritSet& TritSet::operator=(TritSet&& obj) noexcept {

		delete[] memory;

		currentArraySize = obj.currentArraySize;
		currentTritsAmount = obj.currentTritsAmount;
		defaultArraySize = obj.defaultArraySize;
		defaultTritsAmount = obj.defaultTritsAmount;

		obj.memory = nullptr;
		return *this;
	}

	unsigned TritSet::length() {
		for (int i = currentTritsAmount - 1; i >= 0; i--) {
			if (GetTrit(i) != tritsBits::trit::U) return (i + 1);
		}
		return 0;
	}

	void TritSet::trim(unsigned index) {

		for (unsigned i = index; i < currentTritsAmount; i++) {
			SetTrit(i, tritsBits::trit::U);
		}

		defaultTritsAmount = index;

		shrink();

	}

	std::unordered_map<tritsBits::trit, int> TritSet::cardinality() {

		std::unordered_map<tritsBits::trit, int>* newMap = new  std::unordered_map<tritsBits::trit, int>();

		newMap->insert(std::make_pair(tritsBits::trit::T, countTrits(tritsBits::trit::T)));
		newMap->insert(std::make_pair(tritsBits::trit::F, countTrits(tritsBits::trit::F)));
		newMap->insert(std::make_pair(tritsBits::trit::U, countTrits(tritsBits::trit::U)));

		return *newMap;
	}

	unsigned TritSet::countTrits(tritsBits::trit trit) {

		unsigned result = 0;

		for (unsigned i = 0; i < this->length(); i++) {
			if (GetTrit(i) == trit) result++;
		}

		return result;
	}

	 TritSet::TritSet(TritSet&& obj) noexcept {
		currentArraySize = obj.currentArraySize;
		currentTritsAmount = obj.currentTritsAmount;

		defaultArraySize = obj.defaultArraySize;
		defaultTritsAmount = obj.defaultTritsAmount;

		memory = obj.memory;
		obj.memory = nullptr;
	}

	std::ostream& operator << (std::ostream& cout, const TritSet::Ref& ref) {
		cout << (tritsBits::trit)ref;
		return cout;
	}
}
