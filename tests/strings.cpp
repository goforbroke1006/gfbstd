//
// Created by GOFORBROKE on 18.10.2020.
//

#ifndef STRINGS_TEST_H
#define STRINGS_TEST_H

#include <gtest/gtest.h>

#include <vector>

#include "../goxx-std/include/strings.h"

TEST(strings_split, empty_string) {
    ASSERT_EQ(
            goxx_std::strings::Split("", ""),
            std::vector<std::string>()
    );
}

TEST(strings_split, empty_separator) {
    ASSERT_EQ(
            goxx_std::strings::Split("hello", ""),
            std::vector<std::string>({"h", "e", "l", "l", "o"})
    );
}

TEST(strings_split, positive_1) {
    ASSERT_EQ(
            goxx_std::strings::Split("12,,,23,,,34,,,56", ",,,"),
            std::vector<std::string>({"12", "23", "34", "56"})
    );
}

TEST(strings_split, positive_2) {
    ASSERT_EQ(
            goxx_std::strings::Split(",,,12,,,23,,,34,,,56", ",,,"),
            std::vector<std::string>({"", "12", "23", "34", "56"})
    );
}

TEST(strings_split, positive_3) {
    ASSERT_EQ(
            goxx_std::strings::Split("12,,,23,,,34,,,56,,,", ",,,"),
            std::vector<std::string>({"12", "23", "34", "56", ""})
    );
}

TEST(strings_split, positive_4) {
    ASSERT_EQ(
            goxx_std::strings::Split(",,,12,,,23,,,34,,,56,,,", ",,,"),
            std::vector<std::string>({"", "12", "23", "34", "56", ""})
    );
}

TEST(strings_split, negative_1_separator_not_found) {
    ASSERT_EQ(
            goxx_std::strings::Split("hello", "world"),
            std::vector<std::string>({"hello"})
    );
}

TEST(strings_split, negative_1_separator_part_in_begin) {
    ASSERT_EQ(
            goxx_std::strings::Split("hello", "heXX"),
            std::vector<std::string>({"hello"})
    );
}

TEST(strings_split, negative_1_separator_part_in_end) {
    ASSERT_EQ(
            goxx_std::strings::Split("hello", "XXllo"),
            std::vector<std::string>({"hello"})
    );
}

TEST(strings_split, negative_1_separator_part_in_middle) {
    ASSERT_EQ(
            goxx_std::strings::Split("hello", "XllX"),
            std::vector<std::string>({"hello"})
    );
}


/* trimSpace */

TEST(strings_trimSpace, positive_1_left) {
    ASSERT_EQ(
            goxx_std::strings::TrimSpace("  hello"),
            "hello"
    );
}

TEST(strings_trimSpace, positive_2_right) {
    ASSERT_EQ(
            goxx_std::strings::TrimSpace("hello  "),
            "hello"
    );
}

TEST(strings_trimSpace, positive_3_both) {
    ASSERT_EQ(
            goxx_std::strings::TrimSpace("     hello  "),
            "hello"
    );
}

TEST(strings_trimSpace, positive_3_spec) {
    ASSERT_EQ(
            goxx_std::strings::TrimSpace("  \n   hello \t\n "),
            "hello"
    );
}

TEST(strings_trimSpace, negative_empty_string) {
    ASSERT_EQ(
            goxx_std::strings::TrimSpace(""),
            ""
    );
}

/* replace */

TEST(strings_replace, positive_same_length) {
    ASSERT_EQ(
            goxx_std::strings::Replace("hello world", "o", "0"),
            "hell0 w0rld"
    );
}

TEST(strings_replace, positive_diff_length_1) {
    ASSERT_EQ(
            goxx_std::strings::Replace("hello world hello 123 hello", "ell", "++++++"),
            "h++++++o world h++++++o 123 h++++++o"
    );
}

TEST(strings_replace, positive_diff_length_2) {
    ASSERT_EQ(
            goxx_std::strings::Replace("hello worldhello world", "orl", "_"),
            "hello w_dhello w_d"
    );
}

TEST(strings_join, positive_1) {
    ASSERT_EQ(
            goxx_std::strings::Join({"hello", "world", "!!!"}, "_"),
            "hello_world_!!!"
    );
}

TEST(strings_join, positive_2) {
    ASSERT_EQ(
            goxx_std::strings::Join({"hello", "world", "!!!"}, ""),
            "helloworld!!!"
    );
}

TEST(strings_join, negative_1) {
    ASSERT_EQ(
            goxx_std::strings::Join({}, "_"),
            ""
    );
}

TEST(strings_hasPrefix, positive_1) {
    ASSERT_TRUE(goxx_std::strings::HasPrefix("foobar", "foo"));
}

TEST(strings_hasPrefix, positive_2) {
    ASSERT_TRUE(goxx_std::strings::HasPrefix(" foobar", " "));
}

TEST(strings_hasPrefix, positive_3) {
    ASSERT_TRUE(goxx_std::strings::HasPrefix("foobar", ""));
}

TEST(strings_hasPrefix, negative_1) {
    ASSERT_FALSE(goxx_std::strings::HasPrefix("foobar", "oob"));
}

TEST(strings_hasPrefix, negative_2) {
    ASSERT_FALSE(goxx_std::strings::HasPrefix("", "foo"));
}

#endif //STRINGS_TEST_H
