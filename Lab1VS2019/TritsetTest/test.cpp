#include "pch.h"
#include "../Lab1VS2019/TritsBits.h"
#include "../Lab1VS2019/TritSet.h"
TEST(TritSetTests, TritsetStartsUnknown) {

	tritset::TritSet set(1000);

	for (int i = 0; i < 1000; i++) {
		ASSERT_TRUE(set[0] == tritsBits::trit::U);
		ASSERT_TRUE(tritsBits::trit::U == set[0]);
	}

}

TEST(TritSetTests, TritsetDoesntExpand) {

	tritset::TritSet set(1000);

	unsigned defaultCapacity = set.capacity();

	set[1'000'000'000] = tritsBits::trit::U;

	ASSERT_TRUE(set.capacity() == defaultCapacity);
}

TEST(TritSetTests, TritsetShrinkUnknowns) {

	tritset::TritSet set(1000);

	unsigned defaultCapacity = set.capacity();

	set[10'000] = tritsBits::trit::T;

	ASSERT_TRUE(set.capacity() >= defaultCapacity);

	set[10'000] = tritsBits::trit::U;

	ASSERT_TRUE(set.capacity() == defaultCapacity);
}