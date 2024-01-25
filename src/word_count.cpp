#include <iostream>
#include <fstream>
#include "word_count.hpp"
using namespace std;


void to_lowercase(string& str)
{
    for (int i = 0; i < int(str.length()); ++i) {
        if (isupper(str[i])) {
            str[i] += 32;
        }
    }
}

set<string> load_stopwords(istream& stopwords)
{
    string w;
    set<string> sw;
    while (stopwords >> w) {
        to_lowercase(word);
        sw.insert(word);
    }
    return sw;
}

map<string, int> count_words(istream& document, const set<string>& stopwords)
{
    map<string, int> a;
    string word;
    while (document >> word) {
        to_lowercase(word);
        if (a.find(word) != a.end()) {
            ++a[word];
        } else if (stopwords.find(word) == stopwords.end()) {
            a[word] = 1;
        }
    }
    return a;
}      

void output_word_counts(const map<string, int>& word_counts, ostream& output)
{
    for (auto word : word_counts) {
        output << word.first << " " << word.second << endl;
    }
}
