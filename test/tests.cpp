// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include <ctime>
#include "../include/market.h"
TEST(TEST1, ServedB) {
srand(time(nullptr));
Supermarket* supermarket = new Supermarket(20, 40, 500, 5, 20, 1);
supermarket->run();
ASSERT_TRUE(supermarket->ServedB() == 20);
}
TEST(TEST2, NServedB) {
srand(time(nullptr));
Supermarket* supermarket = new Supermarket(20, 40, 500, 5, 20, 1);
supermarket->run();
ASSERT_TRUE(supermarket->NServedB() == 0);
}
TEST(TEST3, InQueue) {
srand(time(nullptr));
Supermarket* supermarket = new Supermarket(20, 40, 500, 5, 20, 1);
supermarket->run();
ASSERT_TRUE(static_cast<int>(supermarket->InQueue()) == 0);
}
TEST(TEST4, RelThrough) {
srand(time(nullptr));
Supermarket* supermarket = new Supermarket(20, 40, 500, 5, 20, 1);
supermarket->run();
ASSERT_TRUE(static_cast<int>(supermarket->RelThrough()) == 1);
}

TEST(TEST5, AbsoluteBand) {
srand(time(nullptr));
Supermarket* supermarket = new Supermarket(20, 40, 500, 5, 20, 1);
supermarket->run();
ASSERT_TRUE(static_cast<int>(supermarket->AbsoluteBand()) == 40);
}
