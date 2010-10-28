// Copyright © 2010 Bart Massey
// Illustration of "Zipf's Law"
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <map>
#include <list>

using namespace std;

map<string, int> freq_map;
string current_word;
bool in_word = false;

void add_word() {
    if (in_word) {
	freq_map[current_word]++;
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

bool count_compare(pair<string, int> fc1, pair<string, int> fc2) {
    return fc1.second < fc2.second;
}

void show_freqs() {
    /* sort the frequencies */
    map<string, int>::iterator itm;
    list< pair<string, int> > freq_list;
    for (itm = freq_map.begin(); itm != freq_map.end(); itm++)
	freq_list.push_back(*itm);
    freq_list.sort(count_compare);
    /* actually show the calculation */
    int i = freq_list.size();
    list< pair<string, int> >::iterator itp;
    for (itp = freq_list.begin(); itp != freq_list.end(); itp++) {
	const char *w = itp->first.c_str();
	int c = itp->second;
	printf("%g %d\n", 1.0 / i--, c);
    }
}

int main ()
{
    read_words();
    show_freqs();
    return 0;
}
