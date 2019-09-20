#pragma once

#include "TritsBits.h"

namespace tritset {

	void CopyUnsignedArray(const unsigned * source, unsigned ** target, unsigned size);

	class TritSet {

	private:

		int ArraySize;
		int TritsAmount;

		unsigned *memory;

	public:

		class Ref {
		protected:

			unsigned *cell;
			unsigned index;

		public:

			Ref(unsigned *cell, unsigned index) : cell(cell), index(index) {}
			~Ref() { }

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
			unsigned *memory;
		public:
			OutBoundsRef(unsigned *cell, unsigned localIndex, unsigned GlobalIndex, unsigned *memory) : Ref(cell, localIndex), globalIndex(GlobalIndex), memory(memory) { }
			~OutBoundsRef() { 
			
				if (*cell != 0) {
					// Расширить память
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

