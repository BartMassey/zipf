// Copyright © 2010 Bart Massey
// Illustration of "Zipf's Law"
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <map>

using namespace std;

map<string, int> freq;
string current_word;
bool in_word = false;

void add_word() {
    if (in_word) {
	freq[current_word]++;
	in_word = false;
    }
}

void read_words() {
    int ch;
    while ((ch = getchar()) != EOF) {
	if (isalpha(ch)) {
	    char chl = tolower(ch);
	    if (!in_word) {
		current_word = string(1, chl);
		in_word = true;
	    } else {
		current_word += chl;
	    }
	    continue;
	}
	add_word();
    }
    add_word();
}

void show_freqs() {
    map<string, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++) {
	const char *w = it->first.c_str();
	int c = it->second;
	printf("%s %d\n", w, c);
    }
}

int main ()
{
    read_words();
    show_freqs();
    return 0;
}
