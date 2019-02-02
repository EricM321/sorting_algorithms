#include <vector>
#include <gtest/gtest.h>
#include "../src/quicksort.cc"
namespace hoare{
    #include "../src/hoare_quicksort.cc"
}

TEST(SwapTest, Lomuto){
	std::vector<int> actual = {3};
	std::vector<int> dummy = {2};
	std::vector<int> expected = {2};
	
	swap(&actual[0], &dummy[0]);
	ASSERT_EQ(expected, actual);
}

TEST(PartitionTest, Lomuto){
	std::vector<int> dummy = {6, 2, 5, 4, 1, 3};
	int actual = partition(dummy, 0, 5, dummy[dummy.size()-1]);
	
	ASSERT_EQ(2, actual);
}

TEST(QuicksortTest, Lomuto) {
	std::vector<int> actual = {2, 1, 3, 5, 4};
	std::vector<int> expected = {1, 2, 3, 4, 5};
	
	quicksort(actual);
    ASSERT_EQ(expected, actual);
}

TEST(SwapTest, Hoare){
	std::vector<int> actual = {3};
	std::vector<int> dummy = {2};
	std::vector<int> expected = {2};

	hoare::swap(&actual[0], &dummy[0]);
	ASSERT_EQ(expected, actual);
}

TEST(PartitionTest, Hoare){
	std::vector<int> dummy = {6, 2, 5, 4, 1, 3};
	int actual = hoare::partition(dummy, 0, dummy.size()-1, dummy[(dummy.size()-1) / 2]);

	ASSERT_EQ(3, actual);
}

TEST(QuicksortTest, Hoare) {
	std::vector<int> actual = {2, 1, 3, 5, 4};
	std::vector<int> expected = {1, 2, 3, 4, 5};

	hoare::hoareQuicksort(actual);
    ASSERT_EQ(expected, actual);
}

TEST(QuicksortTest, HoareNegativeIntegers) {
	std::vector<int> actual = {2, -1, 3, -5, 4};
	std::vector<int> expected = {-5, -1, 2, 3, 4};

	hoare::hoareQuicksort(actual);
    ASSERT_EQ(expected, actual);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}