#include <iostream>
using namespace std;
#include "letter_count.hpp"

constexpr int N_CHARS = ('Z' - 'A' + 1);

int main()
{
	int counts[N_CHARS] = {0};
	string line;
	while (getline(cin, line)) {
		count(line, counts);


	}
	print_counts(counts, N_CHARS);

	return 0;

}
