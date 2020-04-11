#!/bin/sh

set -euo pipefail
IFS=$'\n\t'

main() {
  mkdir -p output
  ./bin/arraylist | tee ./output/arraylist.csv
  ./bin/linkedlist | tee ./output/linkedlist.csv
  ./bin/generate-report
}

main
