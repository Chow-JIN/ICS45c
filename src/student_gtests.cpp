#include <gtest/gtest.h>

#include <sstream>

#include "word_count.h"

using namespace std;

TEST(WordCount, ToLowercase) 
{
	string input = "Hello World";
    to_lowercase(input);
    EXPECT_EQ(input, "hello world");
}


TEST(WordCount, LoadStopWords)
{
	stringstream stopwords_stream("the\nthat\nthis\n");
    set<string> stopwords = load_stopwords(stopwords_stream);
    EXPECT_TRUE(stopwords.count("the") > 0);
    EXPECT_TRUE(stopwords.count("that") > 0);
    EXPECT_TRUE(stopwords.count("this") > 0);
    EXPECT_FALSE(stopwords.count("notstopword") > 0);
}


TEST(WordCount, CountWords)
{
	stringstream document_stream("happy sad happy ics");
    set<string> stopwords = { "banana" };
    map<string, int> word_counts = count_words(document_stream, stopwords);

    EXPECT_EQ(word_counts["happy"], 2);
    EXPECT_EQ(word_counts["sad"], 0);
    EXPECT_EQ(word_counts["ics"], 1);

}


TEST(WordCount, OutputWordCounts)
{
	map<string, int> word_counts = { {"happy", 2}, {"sad", 1} };
    stringstream output_stream;
    output_word_counts(word_counts, output_stream);

    string output_str = output_stream.str();
    EXPECT_TRUE(output_str.find("happy 2") != string::npos);
    EXPECT_TRUE(output_str.find("sad 1") != string::npos);
}



