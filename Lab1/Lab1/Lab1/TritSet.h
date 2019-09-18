#pragma once

namespace tritset {

	enum trit {T, F, U};

	void CopyUnsignedArray(const unsigned * source, unsigned ** target, unsigned size);

	class TritSet {

	private:

		int ArraySize;
		int TritsAmount;
	public:
		unsigned *memory;

	public:


		TritSet(int size);
		TritSet(TritSet &tritSet);

		~TritSet();
	};
}

