#pragma once

#include "TritsBits.h"
#include <iostream>
#include <unordered_map>

namespace tritset {

	void CopyUnsignedArray(const unsigned* source, unsigned** target, unsigned size);

	class TritSet {

	private:

		unsigned defaultArraySize;
		unsigned defaultTritsAmount;

		unsigned currentArraySize;
		unsigned currentTritsAmount;

		unsigned* memory;

		void ReduceMemory(unsigned lastValidTritIndex);
		void ExpandMemory(unsigned index);

		void SetTrit(unsigned index, tritsBits::trit trit);

		tritsBits::trit GetTrit(unsigned index);

	public:

		class Ref {
		private:

			TritSet* tritSet;

			unsigned index;
	
		public:

			Ref(unsigned index,TritSet* tritSet) : index(index), tritSet(tritSet) { }
			
			Ref& operator = (tritsBits::trit trit) {
				tritSet->SetTrit(index, trit);
				return *this;
			}

			Ref& operator = (Ref& ref) {
				*this = (tritsBits::trit)ref;
				return *this;
			}

			operator tritsBits::trit() const {
				return tritSet->GetTrit(index);
			}

		};

		TritSet(unsigned size);
		TritSet(TritSet& tritSet);
		TritSet(TritSet&& obj) noexcept;

		~TritSet();

		unsigned capacity() { return currentArraySize; }
		unsigned GetTritsAmount() { return currentTritsAmount; }

		void shrink();

		Ref operator [] (const unsigned index);
		tritsBits::trit operator [] (const unsigned index) const;

		TritSet operator & (TritSet tritSet);
		TritSet operator | (TritSet tritSet);
		TritSet operator ~ ();

		TritSet& operator = (const TritSet &tritSet);
		TritSet& operator= (TritSet&& obj) noexcept;

		unsigned countTrits(tritsBits::trit trit);
		unsigned length();

		void trim(unsigned index);

		std::unordered_map< tritsBits::trit, int > cardinality();

	};

	std::ostream& operator << (std::ostream& cout, const TritSet::Ref &trit);
}

