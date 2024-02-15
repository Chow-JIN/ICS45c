#include <gtest/gtest.h>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;

    EXPECT_EQ(foo_list->data, 'f');
    // ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);

    list::free(foo_list_head);
}

TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);
}

TEST(ListTests, Print) {
    stringstream output;
    Node* const head = list::from_string("foo");
    list::print(output, head);
    EXPECT_EQ(output.str(), "foo");
    list::free(head);

    stringstream output2;
    Node* const empty = list::from_string("");
    list::print(output2, empty);
    EXPECT_EQ(output2.str(), "");
    list::free(empty);
}

TEST(ListTests, Copy) {
    stringstream output1;
    Node* const head1 = list::from_string("foo");
    Node* p = list::copy(head1);
    list::print(output1, p);
    EXPECT_EQ(output1.str(), "foo");
    list::free(head1);
    list::free(p);

    stringstream output2;
    Node* const head2 = list::from_string("");
    Node* n = list::copy(head2);
    list::print(output2, n);
    EXPECT_EQ(output2.str(), "");
    list::free(head2);
    list::free(n);
}

TEST(ListTests, CompareFull) {
    Node* const head1 = list::from_string("foo");
    Node* const head2 = list::from_string("foo");
    EXPECT_EQ(list::compare(head1, head2), 0);
    list::free(head2);

    Node* const head3 = list::from_string("fooa");
    Node* const head4 = list::from_string("foob");
    EXPECT_LT(list::compare(head3, head4), 0);
    EXPECT_GT(list::compare(head4, head3), 0);
    list::free(head3);
    list::free(head4);

    Node* const head5 = list::from_string("");
    EXPECT_LT(list::compare(head5, head1), 0);
    EXPECT_GT(list::compare(head1, head5), 0);
    list::free(head1);
    list::free(head5);
}

TEST(ListTests, CompareN) {
    Node* const head1 = list::from_string("Hello world");
    Node* const head2 = list::from_string("Hello");
    EXPECT_EQ(list::compare(head1, head2, 5), 0);
    EXPECT_GT(list::compare(head1, head2, 20), 0);
    EXPECT_LT(list::compare(head2, head1, 10), 0);
    list::free(head2);

    Node* const head3 = list::from_string("Hello world");
    EXPECT_EQ(list::compare(head1, head3, 10), 0);
    EXPECT_EQ(list::compare(head3, head1, 100), 0);
    list::free(head3);
}

TEST(ListTests, Reverse) {
    stringstream output1;
    Node* const head1 = list::from_string("foo");
    Node* r_1 = list::reverse(head1);
    list::print(output1, r_1);
    EXPECT_EQ(output1.str(), "oof");
    list::free(head1);
    list::free(r_1);

    stringstream output2;
    Node* const head2 = list::from_string("");
    Node* r_2 = list::reverse(head2);
    list::print(output2, r_2);
    EXPECT_EQ(output2.str(), "");
    list::free(head2);
    list::free(r_2);
}

TEST(ListTests, Append) {
    stringstream output1;
    Node* const head1 = list::from_string("Harley");
    Node* const head2 = list::from_string("JIN");
    Node* append_1 = list::append(head1, head2);
    list::print(output1, append_1);
    EXPECT_EQ(output1.str(), "HarleyJIN");
    list::free(head2);
    list::free(append_1);


}

TEST(ListTests, Index) {
   Node* const head1 = list::from_string("foo");
   EXPECT_EQ(list::index(head1, head1), 0);
   list::free(head1);
}

TEST(ListTests, find_char) {
    Node* const head1 = list::from_string("foo");
    Node *result1 = list::find_char(head1, 'f'); 
    Node *result2 = list::find_char(head1, '\0'); 

    EXPECT_EQ(list::index(head1, result1), 0);
    EXPECT_EQ(list::index(head1, result2), 3);
    list::free(head1);

  
}

TEST(ListTests, find_list) {
    Node* head1 = list::from_string("I am foo");
  	Node* find1 = list::from_string("am");
    Node* result1 = list::find_list(head1, find1);
	EXPECT_EQ(list::index(head1, result1), 2);
    list::free(find1);

}

TEST(ListTests, Nth) {
    Node *head1{list::from_string("fooa")}, *result1{list::nth(head1, 3)};
    EXPECT_EQ(result1->data, 'a');
    list::free(head1);
}

TEST(ListTests, Last) {
    Node *head1{list::from_string("Harley")}, *result1{list::last(head1)};
    EXPECT_EQ(result1->data, 'y');
    list::free(head1);
}
