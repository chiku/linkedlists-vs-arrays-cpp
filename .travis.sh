#!/bin/bash

set -euo pipefail
IFS=$'\n\t'

cpp_prereqs() {
  sudo apt-get update
  sudo apt-get install libboost-test-dev lcov
}

cpp_build() {
  cd linkedlist && make clean coverage && cd ..
  cd arraylist && make clean coverage && cd ..
}

main() {
  cpp_prereqs
  cpp_build
}

main
