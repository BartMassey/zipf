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

void
show_freqs()
{
    /* sort the frequencies */
    map <string, int>::iterator itm;
    list <int>                  freq_list;
    for (itm = freq_map.begin(); itm != freq_map.end(); itm++)
	freq_list.push_back(itm->second);
    freq_list.sort();
    /* actually show the calculation */
    int i = freq_list.size();
    list <int>::iterator itp;
    for (itp = freq_list.begin(); itp != freq_list.end(); itp++)
	printf("%g %d\n", 1.0 / i--, *itp);
}

int
main ()
{
    count_words();
    show_freqs();
    return 0;
}
