#!/bin/bash

set -euo pipefail
IFS=$'\n\t'

main() {
  make clean coverage
  make clean compile
}

main
