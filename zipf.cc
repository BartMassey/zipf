// Copyright © 2010 Bart Massey
// Illustration of "Zipf's Law"

// This program is released under the terms of the "MIT
// License".  Please see the file COPYING in this
// distribution for license details.

#include <ctype.h>
#include <stdio.h>

#include <list>
#include <map>
#include <string>

using namespace std;

map <string, int> freq_map;
string current_word;
bool in_word = false;

// Count the alphabetic words on the input into the frequency map.
void
count_words()
{
    int    ch;
    bool   in_word = false;
    string current_word;
    do {
        ch = getchar();
        if (isascii(ch) && isalpha(ch)) {
            if (in_word) {
                current_word += tolower(ch);
            } else {
                current_word = string(1, tolower(ch));
                in_word = true;
            }
        } else {
            if (in_word) {
                freq_map[current_word]++;
                in_word = false;
            } else {
                /* do nothing */
            }
        }
    } while (ch != EOF);
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
	int c = itp->second;
	printf("%g %d\n", 1.0 / i--, c);
    }
}

int main ()
{
    count_words();
    show_freqs();
    return 0;
}
