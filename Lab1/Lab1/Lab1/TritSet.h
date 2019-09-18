#pragma once

namespace tritset {

	enum trit {T, F, U};

	class TritSet {

	private:
		int ArraySize;
		int TritsAmount;
	public:
		unsigned *memory;

	public:

		static void CopyUnsignedArray(const unsigned * source, unsigned ** target, unsigned size);

		TritSet(int size);
		TritSet(TritSet &tritSet);
		~TritSet();
	};
}

