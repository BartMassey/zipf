# Zipf's Law Demo done several ways
Copyright (c) 2010 Bart Massey

This code comprises a
[Zipf's Law](http://en.wikipedia.org/wiki/Zipf%27s_law)
calculator in various languages, largely as an example for a
software engineering course I taught in 2010.

The included sample text file `swift.txt` is "Tom Swift And
His Electric Runabout" from Project Gutenberg, although the
attribution has been stripped out for the sake of the
analysis. There is also a file `eztest.txt` for checking
that the software is working correctly.

## Build and Run

The included `Makefile` can build any and all of the
following programs. The programs read text from standard
input and output a histogram of word frequencies sorted by
word frequency rank order. Gnuplot can be used to display
the output histogram.

* `zipf.sh`: A standalone shell script version.

* `zipf-cc`: A C++ version.

* `zipf-hs`: A Haskell version. This version requires an
  installation of GHC (Debian package `ghc`) to build.

* `zipf-cc-graphical`: A C++ version with graphical
   display. Takes the source text as an argument. This
   version requires `pkgconfig`, `libplot`, and the
   `libplot` Cairo driver (Debian packages `pkgconfig`,
   `libplot-dev` and `libplot-cairo`) to build.

## License

This work is released under the "MIT License". Please see
the file `COPYING` in this distribution for license terms.
