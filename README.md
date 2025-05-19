[![Build Status](https://github.com/chiku/linkedlists-vs-arrays-cpp/actions/workflows/build.yml/badge.svg)](https://github.com/chiku/linkedlists-vs-arrays-cpp/actions/workflows/build.yml)

Purpose
=======

Prove that insertions into arrays are faster than insertions into linked-lists.

Prerequisites
-------------
* A C++ compiler
* make
* lcov

How to run the benchmarks
-------------------------

* Clone the repository
```
git clone https://github.com/chiku/linkedlists-vs-arrays-cpp.git
```

* Nagivate to the source code
```
cd linkedlists-vs-arrays-cpp
```

* Install `lcov`. Run the following for Ubuntu, Debian etc.
```
sudo apt install lcov
```

* Run test [optional]
```
make clean coverage
```

* Build the app
```
make clean compile
```

* Run the app
```
./run.sh
```

* Open ./public/index.html in a web browser

Result
------

Precomputed results are available at http://htmlpreview.github.io/?https://github.com/chiku/linkedlists-vs-arrays-cpp/blob/main/public/index.html


Check equivalent repository for golang here - https://github.com/chiku/linkedlists-vs-arrays-golang


License
-------
This software is released under the MIT license. Please refer to LICENSE for more details.

[doctest](https://github.com/doctest/doctest) is released under the MIT license.
