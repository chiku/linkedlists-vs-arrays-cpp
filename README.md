Purpose
=======

Prove that insertions into arrays are faster than insertions into linked-lists.

Prerequisites
-------------
* Ruby
* Bundler gem
* make
* A C++ compiler
* Boost test library

You can boost test library on Ubuntu using ```sudo apt-get install libboost-test-dev```


How to run the benchmarks
-------------------------

* Clone the repository
```
git clone https://github.com/chiku/linkedlists-vs-arrays.git -b cpp
```
* Nagivate to the source code
```
cd linkedlists-vs-arrays
```
* Run bundle
```
bundle
```
* Run run-all.sh
```
./run-all.sh
```

Result
------

You can view the results by opening *public/index.html* in a web-browser. You can also open *result.xlsx* in a [spreadsheet application](https://www.libreoffice.org/download/).

Precomputed results are available at http://chiku.github.io/linkedlists-vs-arrays/

License
-------
This software is released under the MIT license. Please refer to LICENSE for more details.
