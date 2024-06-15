/*
 * DO NOT MAKE ANY CHANGES TO THE FUNCTIONS Unless it's marked with "TO-DO"
 */

#include <array>
#include "problem_1.h"
#include "gtest/gtest.h"

std::string case_string(int i) {
    std::ostringstream stream;
    stream << "Test case " << i << " failed";
    return stream.str();
}

TEST(problem_1, null_array) {
    std::vector<int> lengths = {0, 1, -2};
    for (int length: lengths) {
        int actual;
        ASSERT_NO_FATAL_FAILURE(actual = Searcher::binary_search(nullptr, length, 3));
        ASSERT_EQ(actual, -1) << case_string(length);   // TODO: add a comment explaining what this line does
    }
}

TEST(problem_1, basic) {
    const int SIZE = 3;
    int *data = new int[SIZE]{1, 2, 3};
    std::vector<int *> array_for_search(5, data);   //TODO: Add comment explaining what this does.

    std::vector<int> search_target = {
            1,
            2,
            3,
            4,
            0,
    };

    std::vector<int> expected_result = {
            0,
            1,
            2,
            -1,
            -1,
    };

    ASSERT_EQ(array_for_search.size(), search_target.size());
    ASSERT_EQ(array_for_search.size(), expected_result.size());

    for (int i = 0; i < array_for_search.size(); i++) {
        // "expect" is what we think the result SHOULD BE
        int expect = expected_result[i];

        // "actual" is what we actually get, hence the name, from calling our function to be tested
        int actual = Searcher::binary_search(array_for_search[i], SIZE, search_target[i]);

        // The test would pass if the expected value matches the actual value
        ASSERT_EQ(expect, actual) << case_string(i);
    }

    delete[] data;
}

/*
 * TODO: This test needs additional work to pass some validations
 *  Do not change any given lines. OK to add new lines.
 */
TEST(problem_1, in_between) {
    const int SIZE = 2;
    int *data = new int[SIZE]{2, 4};
    std::vector<int *> array_for_search(5, data);

    std::vector<int> search_target = {
            0,
            2,
            3,
            4,
            8,
    };

    std::vector<int> expected_result = {
            -1,
            0,
            -1,
            1,
            -1,
    };

    ASSERT_EQ(array_for_search.size(), search_target.size());
    ASSERT_EQ(array_for_search.size(), expected_result.size());

    for (int i = 0; i < array_for_search.size(); i++) {
        int actual = Searcher::binary_search(array_for_search[i], SIZE, search_target[i]);
        int expect = expected_result[i];
        ASSERT_EQ(expect, actual) << case_string(i);
    }
}

TEST(problem_1, has_duplicates) {
    std::vector<int *> array_for_search = {
            new int[4]{1, 3, 3, 4},
            new int[4]{1, 2, 3, 5},
            new int[1]{3},
            new int[2]{3, 3},
            new int[3]{3, 4, 3},
    };

    std::vector<int> search_target(array_for_search.size(), 3); // Does this need to an array?

    std::vector<int> array_length = {
            4,
            4,
            1,
            2,
            3,
    };

    ASSERT_EQ(array_for_search.size(), search_target.size());

    for (int i = 0; i < array_for_search.size(); i++) {
        int actual = Searcher::binary_search(array_for_search[i], array_length[i], search_target[i]);

        // TODO: add a comment about what this line is checking
        ASSERT_TRUE(actual >= 0 && actual < array_length[i]) << case_string(i);

        // TODO: add a comment about what this line is checking
        ASSERT_EQ(array_for_search[i][actual], search_target[i]) << case_string(i);

        delete[] array_for_search[i];
    }
}