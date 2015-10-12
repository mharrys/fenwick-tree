# Fenwick tree
Implementation of a Fenwick tree as described by Peter M. Fenwick. It will
pass [Kattis](https://open.kattis.com/problems/fenwick).

## How-to
For running tests you will need [Google C++ Testing
Framework](https://code.google.com/p/googletest/) and [Google C++ Mocking
Framework](https://code.google.com/p/googlemock/).

Build with [SCons](http://www.scons.org) from root directory.

  $ scons
  $ cd bin
  $ ./run_all_tests

You can also run the Kattis test cases.

  $ cat kattis/fenwick1.in | ./fenwick

## References
Peter M. Fenwick. "A new data structure for cumulative frequency tables".
Software: Practice and Experiences 24 (3): 327-336, 1994.
