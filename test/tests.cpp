// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include <ctime>
#include "../include/market.h"
TEST(TEST1, ServedBuyers) {
srand(time(nullptr));
Supermarket* supermarket = new Supermarket(20, 40, 500, 5, 20, 1);
supermarket->run();
ASSERT_TRUE(result->ServedBuyers() == 20);
}
