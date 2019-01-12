#include "../src/quicksort.cc"
#include <vector>
#include <gtest/gtest.h>

TEST(QuicksortTest, PositiveNosArray) {
	std::vector<int> unsortedNumbers = {2, 1, 3, 5, 4};
	std::vector<int> expected = {1, 2, 3, 4, 5};
	
    ASSERT_EQ(expected, quicksort(unsortedNumbers));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}