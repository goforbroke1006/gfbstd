//
// Created by GOFORBROKE on 18.10.2020.
//

#ifndef STRINGS_TEST_H
#define STRINGS_TEST_H

#include <gtest/gtest.h>

#include <vector>

#include "../goxx-std-strings.h"

TEST(strings_split, empty_string) {
    ASSERT_EQ(
            goxx_std::strings::split("", ""),
            std::vector<std::string>()
    );
}

TEST(strings_split, empty_separator) {
    ASSERT_EQ(
            goxx_std::strings::split("hello", ""),
            std::vector<std::string>({"h", "e", "l", "l", "o"})
    );
}

TEST(strings_split, positive_1) {
    ASSERT_EQ(
            goxx_std::strings::split("12,,,23,,,34,,,56", ",,,"),
            std::vector<std::string>({"12", "23", "34", "56"})
    );
}

TEST(strings_split, positive_2) {
    ASSERT_EQ(
            goxx_std::strings::split(",,,12,,,23,,,34,,,56", ",,,"),
            std::vector<std::string>({"", "12", "23", "34", "56"})
    );
}

TEST(strings_split, positive_3) {
    ASSERT_EQ(
            goxx_std::strings::split("12,,,23,,,34,,,56,,,", ",,,"),
            std::vector<std::string>({"12", "23", "34", "56", ""})
    );
}

TEST(strings_split, positive_4) {
    ASSERT_EQ(
            goxx_std::strings::split(",,,12,,,23,,,34,,,56,,,", ",,,"),
            std::vector<std::string>({"", "12", "23", "34", "56", ""})
    );
}

TEST(strings_split, negative_1_separator_not_found) {
    ASSERT_EQ(
            goxx_std::strings::split("hello", "world"),
            std::vector<std::string>({"hello"})
    );
}

TEST(strings_split, negative_1_separator_part_in_begin) {
    ASSERT_EQ(
            goxx_std::strings::split("hello", "heXX"),
            std::vector<std::string>({"hello"})
    );
}

TEST(strings_split, negative_1_separator_part_in_end) {
    ASSERT_EQ(
            goxx_std::strings::split("hello", "XXllo"),
            std::vector<std::string>({"hello"})
    );
}

TEST(strings_split, negative_1_separator_part_in_middle) {
    ASSERT_EQ(
            goxx_std::strings::split("hello", "XllX"),
            std::vector<std::string>({"hello"})
    );
}


/* trimSpace */

TEST(strings_trimSpace, positive_1_left) {
    ASSERT_EQ(
            goxx_std::strings::trimSpace("  hello"),
            "hello"
    );
}

TEST(strings_trimSpace, positive_2_right) {
    ASSERT_EQ(
            goxx_std::strings::trimSpace("hello  "),
            "hello"
    );
}

TEST(strings_trimSpace, positive_3_both) {
    ASSERT_EQ(
            goxx_std::strings::trimSpace("     hello  "),
            "hello"
    );
}

TEST(strings_trimSpace, positive_3_spec) {
    ASSERT_EQ(
            goxx_std::strings::trimSpace("  \n   hello \t\n "),
            "hello"
    );
}

TEST(strings_trimSpace, negative_empty_string) {
    ASSERT_EQ(
            goxx_std::strings::trimSpace(""),
            ""
    );
}

/* replace */

TEST(strings_replace, positive_same_length) {
    ASSERT_EQ(
            goxx_std::strings::replace("hello world", "o", "0"),
            "hell0 w0rld"
    );
}

TEST(strings_replace, positive_diff_length_1) {
    ASSERT_EQ(
            goxx_std::strings::replace("hello world hello 123 hello", "ell", "++++++"),
            "h++++++o world h++++++o 123 h++++++o"
    );
}

TEST(strings_replace, positive_diff_length_2) {
    ASSERT_EQ(
            goxx_std::strings::replace("hello worldhello world", "orl", "_"),
            "hello w_dhello w_d"
    );
}

TEST(strings_join, positive_1) {
    ASSERT_EQ(
            goxx_std::strings::join({"hello","world","!!!"}, "_"),
            "hello_world_!!!"
    );
}

TEST(strings_join, positive_2) {
    ASSERT_EQ(
            goxx_std::strings::join({"hello","world","!!!"}, ""),
            "helloworld!!!"
    );
}

TEST(strings_join, negative_1) {
    ASSERT_EQ(
            goxx_std::strings::join({}, "_"),
            ""
    );
}

#endif //STRINGS_TEST_H
