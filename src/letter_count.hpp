int char_to_index(char ch) {
	char cha = toupper(ch);
	int index = cha - 'A';
	return index;

}


char index_to_char(int i) {
	char c = 'A' + i;
	return c;

}


void count(string s, int counts[]) {
	for (char c : s) {
		int index = char_to_index(c);

		++counts[index];

	}
}

void print_counts(int counts[], int len) {
	for (int i = 0; i < len; i ++) {
		char c = index_to_char(i);
		cout << c << "" << counts[i] << "\n";
	}
}
