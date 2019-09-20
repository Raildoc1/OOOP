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

		void SetTrit(int index, tritsBits::trit trit);

	public:

		class Ref {
		protected:

			unsigned *cell;
			unsigned index;

		public:

			Ref(unsigned *cell, unsigned index) : cell(cell), index(index) {
				std::cout << "Ref();" << std::endl;
			}
			virtual ~Ref() {
				std::cout << "~Ref();" << std::endl;
			}

			Ref & operator = (tritsBits::trit trit) {
				tritsBits::SetTrit(cell, index, trit);
				return *this;
			}

			operator tritsBits::trit() {
				return tritsBits::GetTrit(cell, index);
			}

		};

		class OutBoundsRef : public Ref {
		private:

			unsigned globalIndex;
			TritSet *tritSet;

		public:
			OutBoundsRef(unsigned *cell, unsigned localIndex, unsigned GlobalIndex, TritSet *tritSet) : Ref(cell, localIndex), globalIndex(GlobalIndex), tritSet(tritSet) {
				std::cout << "OutBoundsRef();" << std::endl;
			}
			~OutBoundsRef() {
			
				std::cout << "~OutBoundsRef();" << std::endl;

				if (*cell != 0) {
					tritSet->ExpandMemory(globalIndex);
					tritSet->SetTrit(index, tritsBits::GetTrit(cell, index));
				} else {
					delete cell;
				}
			
			}
		};

		TritSet(int size);
		TritSet(TritSet &tritSet);

		~TritSet();

		Ref operator [] (const unsigned index);
		tritsBits::trit operator [] (const unsigned index) const;
		
	};
}

