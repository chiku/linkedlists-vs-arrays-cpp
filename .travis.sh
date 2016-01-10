#!/bin/bash

set -euo pipefail
IFS=$'\n\t'

cpp_prereqs() {
  sudo apt-get update
  sudo apt-get install libboost-test-dev lcov
}

golang_prereqs() {
  sudo apt-get update
  sudo apt-get instal golang
  go get github.com/mattn/gom
}

cpp_build() {
  cd linkedlist && make clean coverage && cd ..
  cd arraylist && make clean coverage && cd ..
}

golang_build() {
  cd arraylist && gom test -coverprofile=coverage.out && gom tool cover -html=coverage.out -o coverage.html && cd ..
  cd linkedlist && gom test -coverprofile=coverage.out && gom tool cover -html=coverage.out -o coverage.html && cd ..
  gom install github.com/chiku/linkedlists-vs-arrays/compare
  gom install github.com/chiku/linkedlists-vs-arrays/create_report
}

main() {
  if [[ "$TRAVIS_BRANCH" == 'cpp' ]]
  then
    cpp_prereqs
    cpp_build
  else
    golang_prereqs
    golang_build
  fi
}

main
