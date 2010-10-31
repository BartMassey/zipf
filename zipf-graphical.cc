// Copyright © 2010 Bart Massey
// Illustration of "Zipf's Law"
// (Self-contained PLplot version.)

// This program is released under the terms of the "MIT
// License".  Please see the file COPYING in this
// distribution for license details.

#include <ctype.h>
#include <plplot.h>
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

// Sort and display frequency data per Zipf's Law.
void
show_freqs()
{
    // Sort the frequencies.
    map <string, int>::iterator itm;
    list <int>                  freq_list;
    for (itm = freq_map.begin(); itm != freq_map.end(); itm++)
	freq_list.push_back(itm->second);
    freq_list.sort();
    // Set up PLplot.
    plinit();
    int nfreq = freq_list.size();
    plenv(0.0, 1.0, 0.0, (PLFLT)nfreq, 0, 1);
    pllab("inv rank", "freq", "");
    // Perform the Zipf calculation.
    list <int>::iterator itp;
    PLFLT *              xs = new PLFLT[nfreq];
    PLFLT *              ys = new PLFLT[nfreq];
    int i = 0;
    int j = nfreq;
    for (itp = freq_list.begin(); itp != freq_list.end(); itp++) {
	xs[i] = 1.0 / j--;
	ys[i] = *itp;
	i++;
    }
    // Display the result.
    plpoin(nfreq, xs, ys, 'x');
    plend();
}

int
main (int argc, const char **argv)
{
    plsdev("xwin");
    plparseopts(&argc, argv, PL_PARSE_FULL | PL_PARSE_NODASH);
    plspause(1);
    count_words();
    show_freqs();
    return 0;
}
