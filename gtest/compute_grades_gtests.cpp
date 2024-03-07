#include <gtest/gtest.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "compute_grades.hpp"

TEST(Student_Gtests, Output) {
    Student s1;
    stringstream s_1{"Name Harley JIN\nQuiz 10 10 10\nHW 10 10 10\nFinal 100"};
    stringstream out1;
    s_1 >> s1;
    s1.compute_grade();
    out1 << s1;
    EXPECT_EQ(out1.str(), std::string("Name:   Harley JIN\nHW Ave: 10\nQZ Ave: 10\nFinal:  100\nTotal:  37\nGrade:  F\n"));

    Student s2;
    stringstream s_2{"Name Harley JIN\nQuiz 0\nFinal 0"};
    stringstream out2;
    s_2 >> s2;
    s2.compute_grade();
    out2 << s2;
    EXPECT_EQ(out2.str(), std::string("Name:   Harley JIN\nHW Ave: 0\nQZ Ave: 0\nFinal:  0\nTotal:  0\nGrade:  F\n"));
}
