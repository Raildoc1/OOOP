#pragma once

#include "TritsBits.h"
#include <iostream>
#include <unordered_map>

namespace tritset {

	void CopyUnsignedArray(const unsigned * source, unsigned ** target, unsigned size);

	class TritSet {

	private:

		unsigned defaultArraySize;
		unsigned defaultTritsAmount;

		unsigned currentArraySize;
		unsigned currentTritsAmount;

		unsigned *memory;

		void ReduceMemory(unsigned lastValidTritIndex);
		void ExpandMemory(unsigned index);

		void SetTrit(unsigned index, tritsBits::trit trit);

		tritsBits::trit GetTrit(unsigned index);

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

			Ref & operator = (Ref & ref) {
				tritsBits::SetTrit(cell, localIndex, tritsBits::GetTrit(ref.cell, ref.localIndex));
				return *this;
			}

			bool operator == (Ref& ref) {
				if (tritsBits::GetTrit(ref.cell, ref.localIndex) == tritsBits::GetTrit(this->cell, this->localIndex)) return true;
				return false;
			}

			bool operator == (const tritsBits::trit trit) {
				if (trit == tritsBits::GetTrit(this->cell, this->localIndex)) return true;
				return false;
			}

			operator tritsBits::trit() {
				return tritsBits::GetTrit(cell, localIndex);
			}

			friend std::ostream & operator << (std::ostream & cout, const tritsBits::trit & trit) {
				
				switch (trit) {
				case tritsBits::U:
					cout << "U";
					break;
				case tritsBits::F:
					cout << "F";
					break;
				case tritsBits::T:
					cout << "T";
					break;
				}

				return cout;
			}

			tritsBits::trit operator & (tritsBits::trit trit);
			tritsBits::trit operator | (tritsBits::trit trit);
			tritsBits::trit operator ~ ();

		};

		TritSet(unsigned size);
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

		void trim(unsigned index);

		std::unordered_map< tritsBits::trit, int > cardinality();

	};
}

