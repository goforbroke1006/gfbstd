//
// Created by gofor on 22.12.2020.
//

#include <gtest/gtest.h>

#include <vector>

#include "../goxx-std-fmt.h"

TEST(fmt_sprintf, simple_1) {
    ASSERT_EQ(
        goxx_std::fmt::sprintf(" %s ", "Hello"),
        " Hello "
    );
}
