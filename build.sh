#!/bin/bash

set -euo pipefail
IFS=$'\n\t'

main() {
  cd linkedlist
  make clean coverage
  make clean compile
  cd ..

  cd arraylist
  make clean coverage
  make clean compile
  cd ..
}

main
