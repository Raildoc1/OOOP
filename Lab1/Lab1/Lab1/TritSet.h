#pragma once

#include "TritsBits.h"
#include <iostream>

namespace tritset {

	void CopyUnsignedArray(const unsigned * source, unsigned ** target, unsigned size);

	class TritSet {

	private:

		int defaultArraySize;
		int defaultTritsAmount;

		int currentArraySize;
		int currentTritsAmount;

		unsigned *memory;

		void ExpandMemory(int index);
		void ReduceMemory(int lastValidTritIndex);

		void SetTrit(int index, tritsBits::trit trit);

		tritsBits::trit GetTrit(int index);

	public:

		class Ref {
		private:

			TritSet *tritSet;
			unsigned *cell;

			unsigned localIndex;
			unsigned globalIndex;

			bool isValid;

		public:

			Ref(unsigned *cell, unsigned localIndex, unsigned globalIndex, TritSet * tritSet, bool isValid) : cell(cell), localIndex(localIndex), globalIndex(globalIndex), tritSet(tritSet), isValid(isValid) { }
			~Ref() {

				if (*cell != 0) {
					tritSet->ExpandMemory(globalIndex);
					tritSet->SetTrit(globalIndex, tritsBits::GetTrit(cell, localIndex));
				} else {
					if(!isValid) delete cell;
				}

				tritSet->shrink();
			}

			Ref & operator = (tritsBits::trit trit) {
				tritsBits::SetTrit(cell, localIndex, trit);
				return *this;
			}

			operator tritsBits::trit() {
				return tritsBits::GetTrit(cell, localIndex);
			}

			tritsBits::trit operator & (tritsBits::trit trit);
			tritsBits::trit operator | (tritsBits::trit trit);
			tritsBits::trit operator ~ ();

		};

		TritSet(int size);
		TritSet(TritSet &tritSet);

		~TritSet();

		unsigned capacity() { return currentArraySize; }
		unsigned GetTritsAmount() { return currentTritsAmount; }

		void shrink();

		Ref operator [] (const unsigned index);
		tritsBits::trit operator [] (const unsigned index) const;
		
		TritSet & operator & (TritSet tritSet);
		TritSet & operator | (TritSet tritSet);
		TritSet & operator ~ ();

		unsigned countTrits(tritsBits::trit trit);
		unsigned length();

	};
}

