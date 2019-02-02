#include "../src/hoare_quicksort.cc"
#include <vector>
#include <gtest/gtest.h>

TEST(HoareSwapTest, Integers){
	std::vector<int> actual = {3};
	std::vector<int> dummy = {2};
	std::vector<int> expected = {2};
	
	swap(&actual[0], &dummy[0]);
	ASSERT_EQ(expected, actual);
}

TEST(HoarePartitionTest, Integers){
	std::vector<int> dummy = {6, 2, 5, 4, 1, 3};
	int actual = partition(dummy, 0, dummy.size()-1);
	
	ASSERT_EQ(3, actual);
}

TEST(HoareQuicksortTest, Integers) {
	std::vector<int> actual = {2, 1, 3, 5, 4};
	std::vector<int> expected = {1, 2, 3, 4, 5};
	
	hoareQuicksort(actual);
    ASSERT_EQ(expected, actual);
}

TEST(HoareQuicksortTest, NegativeIntegers) {
	std::vector<int> actual = {2, -1, 3, -5, 4};
	std::vector<int> expected = {-5, -1, 2, 3, 4};

	hoareQuicksort(actual);
    ASSERT_EQ(expected, actual);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
