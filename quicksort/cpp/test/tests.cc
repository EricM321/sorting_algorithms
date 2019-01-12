#include "../src/quicksort.cc"
#include <vector>
#include <gtest/gtest.h>

TEST(SwapTest, Numbers){
	std::vector<int> actual = {3};
	std::vector<int> dummy = {2};
	std::vector<int> expected = {2};
	
	swap(&actual[0], &dummy[0]);
	ASSERT_EQ(expected, actual);
}

TEST(PartitionTest, Numbers){
	std::vector<int> dummy = {6, 2, 5, 4, 1, 3};
	int actual = partition(dummy, 0, 5);
	
	ASSERT_EQ(2, actual);
}

TEST(QuicksortTest, PositiveNos) {
	std::vector<int> actual = {2, 1, 3, 5, 4};
	std::vector<int> expected = {1, 2, 3, 4, 5};
	
	quicksort(actual);
    ASSERT_EQ(expected, actual);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}