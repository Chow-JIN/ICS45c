#include <iostream>
#include <algorithm>
#include "mapset.hpp"

using namespace std;

string to_lowercase(const string& str){
	string out;
	transform(str.begin(), str.end(), back_inserter(out), [](char s){ return tolower(s); });
	return out;
	}


set<string> load_stopwords(istream& stopwords){
	set<string> out;
    transform(istream_iterator<string>(stopwords), istream_iterator<string>(), inserter(out, out.end()), to_lowercase);
    
    return out;
	}

map<string, int> count_words(istream& document, const set<string>& stopwords){
	map<string, int> out;

	for_each(istream_iterator<string>(document), istream_iterator<string>(), [&](string s){ s = to_lowercase(s); if (stopwords.find(s) == stopwords.end()) ++out[s];});
	return out;
	}				

void output_word_counts(const map<string, int>& word_counts, ostream& output)
{
    for (const auto& [word, count] : word_counts) 
		output << word << ' ' << count << '\n';
}
