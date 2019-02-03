#include <vector>
#include <gtest/gtest.h>
#include "../src/merge_sort.cc"

TEST(mergeTest, TopDown){
    std::vector<int> left = {4, 5, 6};
	std::vector<int> right = {1, 2, 3};
	std::vector<int> actual = merge(left, right);
	std::vector<int> expected = {1, 2, 3, 4, 5, 6};

	ASSERT_EQ(expected, actual);
}

TEST(MergeSortTest, TopDown) {
	std::vector<int> actual = {2, 1, 3, 5, 4};
	std::vector<int> expected = {1, 2, 3, 4, 5};

	merge_sort(actual);
    ASSERT_EQ(expected, actual);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}