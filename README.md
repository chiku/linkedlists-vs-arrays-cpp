[![Build Status](https://travis-ci.org/chiku/linkedlists-vs-arrays.svg?branch=cpp)](https://travis-ci.org/chiku/linkedlists-vs-arrays)

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
cd $GOROOT
mkdir -p chiku
git clone https://github.com/chiku/linkedlists-vs-arrays.git -b cpp
```
* Nagivate to the source code
```
cd linkedlists-vs-arrays
```
* Fetch the prerequisites
```
./prereqs.sh
```
* Build the app
```
./build.sh
```
* Run the app
```
./run.sh
```

Result
------

Precomputed results are available at http://htmlpreview.github.io/?https://github.com/chiku/linkedlists-vs-arrays/blob/cpp/public/index.html

License
-------
This software is released under the MIT license. Please refer to LICENSE for more details.

[catch2](https://github.com/catchorg/Catch2) is released under the Boost Software License.
