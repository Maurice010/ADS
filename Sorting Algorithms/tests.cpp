#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "sorting_algorithms.hpp"

using namespace std;

class HeapSortTest : public ::testing::TestWithParam<vector<int>> {};

TEST_P(HeapSortTest, SortsNumbersCorrectly) {
    vector<int> data = GetParam();
    vector<int> sortedData = data;
    sort(sortedData.begin(), sortedData.end());

    heapSort(data, data.size());

    EXPECT_EQ(data, sortedData);
}

INSTANTIATE_TEST_CASE_P(
    HeapSortTestCases,
    HeapSortTest,
    ::testing::Values(
        vector<int>{},
        vector<int>{1},
        vector<int>{1, 2},
        vector<int>{2, 1},
        vector<int>{1, 2, 3},
        vector<int>{3, 2, 1},
        vector<int>{5, -3, 8, 2, -9, 0},
        vector<int>{-5, -3, -8, -2, -9, 0},
        vector<int>{-5, -3, 100, 100, -5660, -5660, 0, -8, -2, -9, 0}
    )
);

class QuickSortTest : public ::testing::TestWithParam<vector<int>> {};

TEST_P(QuickSortTest, SortsNumbersCorrectly) {
    vector<int> data = GetParam();
    vector<int> sortedData = data;
    sort(sortedData.begin(), sortedData.end());

    quickSort(data, 0, data.size()-1);

    EXPECT_EQ(data, sortedData);
}

INSTANTIATE_TEST_CASE_P(
    QuickSortTestCases,
    QuickSortTest,
    ::testing::Values(
        vector<int>{},
        vector<int>{1},
        vector<int>{1, 2},
        vector<int>{2, 1},
        vector<int>{1, 2, 3},
        vector<int>{3, 2, 1},
        vector<int>{5, -3, 8, 2, -9, 0},
        vector<int>{-5, -3, -8, -2, -9, 0},
        vector<int>{-5, -3, 100, 100, -5660, -5660, 0, -8, -2, -9, 0}
    )
);

class InsertionSortTest : public ::testing::TestWithParam<vector<int>> {};

TEST_P(InsertionSortTest, SortsNumbersCorrectly) {
    vector<int> data = GetParam();
    vector<int> sortedData = data;
    sort(sortedData.begin(), sortedData.end());

    insertionSort(data);

    EXPECT_EQ(data, sortedData);
}

INSTANTIATE_TEST_CASE_P(
    InsertionSortTestCases,
    InsertionSortTest,
    ::testing::Values(
        vector<int>{},
        vector<int>{1},
        vector<int>{1, 2},
        vector<int>{2, 1},
        vector<int>{1, 2, 3},
        vector<int>{3, 2, 1},
        vector<int>{5, -3, 8, 2, -9, 0},
        vector<int>{-5, -3, -8, -2, -9, 0},
        vector<int>{-5, -3, 100, 100, -5660, -5660, 0, -8, -2, -9, 0}
    )
);

class MergeSortTest : public ::testing::TestWithParam<vector<int>> {};

TEST_P(MergeSortTest, SortsNumbersCorrectly) {
    vector<int> data = GetParam();
    vector<int> sortedData = data;
    sort(sortedData.begin(), sortedData.end());

    mergeSort(data, 0, data.size()-1);

    EXPECT_EQ(data, sortedData);
}

INSTANTIATE_TEST_CASE_P(
    MergeSortTestCases,
    MergeSortTest,
    ::testing::Values(
        vector<int>{},
        vector<int>{1},
        vector<int>{1, 2},
        vector<int>{2, 1},
        vector<int>{1, 2, 3},
        vector<int>{3, 2, 1},
        vector<int>{5, -3, 8, 2, -9, 0},
        vector<int>{-5, -3, -8, -2, -9, 0},
        vector<int>{-5, -3, 100, 100, -5660, -5660, 0, -8, -2, -9, 0}
    )
);

class BubbleSortTest : public ::testing::TestWithParam<vector<int>> {};

TEST_P(BubbleSortTest, SortsNumbersCorrectly) {
    vector<int> data = GetParam();
    vector<int> sortedData = data;
    sort(sortedData.begin(), sortedData.end());

    bubbleSort(data);

    EXPECT_EQ(data, sortedData);
}

INSTANTIATE_TEST_CASE_P(
    BubbleSortTestCases,
    BubbleSortTest,
    ::testing::Values(
        vector<int>{},
        vector<int>{1},
        vector<int>{1, 2},
        vector<int>{2, 1},
        vector<int>{1, 2, 3},
        vector<int>{3, 2, 1},
        vector<int>{5, -3, 8, 2, -9, 0},
        vector<int>{-5, -3, -8, -2, -9, 0},
        vector<int>{-5, -3, 100, 100, -5660, -5660, 0, -8, -2, -9, 0}
)
);

class SelectionSortTest : public ::testing::TestWithParam<vector<int>> {};

TEST_P(SelectionSortTest, SortsNumbersCorrectly) {
    vector<int> data = GetParam();
    vector<int> sortedData = data;
    sort(sortedData.begin(), sortedData.end());

    selectionSort(data);

    EXPECT_EQ(data, sortedData);
}

INSTANTIATE_TEST_CASE_P(
    SelectionSortTestCases,
    SelectionSortTest,
    ::testing::Values(
        vector<int>{},
        vector<int>{1},
        vector<int>{1, 2},
        vector<int>{2, 1},
        vector<int>{1, 2, 3},
        vector<int>{3, 2, 1},
        vector<int>{5, -3, 8, 2, -9, 0},
        vector<int>{-5, -3, -8, -2, -9, 0},
        vector<int>{-5, -3, 100, 100, -5660, -5660, 0, -8, -2, -9, 0}
)
);