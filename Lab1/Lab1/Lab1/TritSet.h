#pragma once

#include "TritsBits.h"

namespace tritset {

	void CopyUnsignedArray(const unsigned * source, unsigned ** target, unsigned size);

	class TritSet {

	private:

		int ArraySize;
		int TritsAmount;
	public:
		unsigned *memory;

	public:

		class ref {
		private:
			unsigned *cell;
			unsigned index;
		public:

			ref(unsigned *cell, unsigned index) : cell(cell), index(index) {}
			~ref() { delete cell; }

			ref & operator = (tritsBits::trit trit) {
				tritsBits::SetTrit(cell, index, trit);
				return *this;
			}

			const bool operator == (tritsBits::trit trit) {

				if (tritsBits::GetTrit(cell, index) == trit) return true;
				else return false;

			}

		};

		TritSet(int size);
		TritSet(TritSet &tritSet);

		~TritSet();

		//tritsBits::trit operator [] (const unsigned index) const;
		ref operator [] (unsigned index);

		
	};
}

