#include <gtest/gtest.h>
#include "../src/transactionLogger.hpp"
#include <iostream>

TEST(test_transactionLogger, test_helloworld) {
    std::cout << "Testing hello world.\nIt seems to work." << std::endl;
    EXPECT_EQ(1, 1);
}
