#include "process_numbers.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void split_odd_even(istream & numbers, ostream & odds, ostream& evens)
{
	vector<int> V;
	std::copy(istream_iterator<int>(numbers), istream_iterator<int>(), back_inserter(V));
	sort(V.begin(), V.end());
    std::copy_if(V.begin(), V.end(), ostream_iterator<int>(odds, " "), [](int i) { return i%2 != 0; });
    odds << endl;
    std::copy_if(V.begin(), V.end(), ostream_iterator<int>(evens, "\n"), [](int i) { return i%2 == 0; });


}






