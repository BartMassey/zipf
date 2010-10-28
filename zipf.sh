#!/bin/sh
# Copyright © 2010 Bart Massey
# Illustration of "Zipf's Law"

# This program is released under the terms of the "MIT
# License".  Please see the file COPYING in this
# distribution for license details.

tr -c a-zA-Z '\n' |
grep -v '^$' |
tr A-Z a-z | 
sort |
uniq -c |
sed 's/^ *//' |
sort -k 1rn -k 2 |
awk '{if (f==0 || $1 < f) print ++n, $1; f = $1;}' |
sort -k 1rn |
awk '{print 1.0/$1, $2;}'
