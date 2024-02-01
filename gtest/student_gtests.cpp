#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
	char haha[666];
    EXPECT_EQ(String::strncpy(haha, "666", 2), haha);
    EXPECT_STREQ(haha, "66");
}

TEST(StringFunction, strcat) {
	char name[10] = "SHI";
    EXPECT_EQ(String::strcat(name, "JIN"), name);
    EXPECT_STREQ(name, "SHIJIN");
}

TEST(StringFunction, strncat) {
	char name[10] = "SHI";
	EXPECT_EQ(String::strncat(name, "JIN666", 3), name);
	EXPECT_STREQ(name, "SHIJIN");
}

TEST(StringFunction, strcmp) {
    EXPECT_LT(String::strcmp("ABC", "def"), 0);
	EXPECT_GT(String::strcmp("def", "ABC"), 0);
	EXPECT_EQ(String::strcmp("abc", "abc"), 0);
}

TEST(StringFunction, strncmp) {
    EXPECT_EQ(String::strncmp("abc", "abcd", 3), 0);
    EXPECT_GT(String::strncmp("ABc", "ABCdEFGHIJK", 3), 0);
    EXPECT_LT(String::strncmp("ABC", "ABcDEFJ", 3), 0);
}

TEST(StringFunction, reverse_cpy) {
    char copy[10];
    String::reverse_cpy(copy, "abc");
    EXPECT_STREQ(copy, "cba");
}

TEST(StringFunction, strchr) {
    char a[10] = "TESTME";
	EXPECT_EQ(String::strchr(a, 'E'), (a + 1));
}

TEST(StringFunction, strstr) {
    char a[10] = "TESTME";
    EXPECT_EQ(String::strstr(a, "ME"), (a + 4));
}
