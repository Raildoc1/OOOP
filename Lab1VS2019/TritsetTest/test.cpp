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

	set.shrink();

	ASSERT_TRUE(set.capacity() == defaultCapacity);
}

TEST(TritSetTests, TritsetOutOfBounds) {

	tritset::TritSet set(100);

	unsigned defaultCapacity = set.capacity();

	if(set[1'000'000'000] == tritsBits::trit::T) {}

	ASSERT_TRUE(set.capacity() == defaultCapacity);
}

TEST(TritSetTests, TritsetTrim) {

	tritset::TritSet set(1000);

	unsigned defaultCapacity = set.capacity();

	set.trim(5);

	ASSERT_TRUE(set.capacity() < defaultCapacity);
}

TEST(TritSetTests, TritsetLength) {

	tritset::TritSet set(1000);

	ASSERT_TRUE(set.length() == 0);
}

TEST(TritSetTests, CountTrits) {

	tritset::TritSet set(1000);

	ASSERT_TRUE(set.countTrits(tritsBits::trit::U) == 0);
	ASSERT_TRUE(set.countTrits(tritsBits::trit::T) == 0);
	ASSERT_TRUE(set.countTrits(tritsBits::trit::F) == 0);

	set[500] = tritsBits::trit::T;

	ASSERT_TRUE(set.countTrits(tritsBits::trit::U) == 500);
	ASSERT_TRUE(set.countTrits(tritsBits::trit::T) == 1);
	ASSERT_TRUE(set.countTrits(tritsBits::trit::F) == 0);

	for (int i = 0; i < 1000; i += 2) {
		set[i] = tritsBits::trit::T;
		set[i+1] = tritsBits::trit::F;
	}

	ASSERT_TRUE(set.countTrits(tritsBits::trit::U) == 0);
	ASSERT_TRUE(set.countTrits(tritsBits::trit::T) == 500);
	ASSERT_TRUE(set.countTrits(tritsBits::trit::F) == 500);
}