#!/bin/bash

set -euo pipefail
IFS=$'\n\t'

main() {
  sudo apt-get update
  sudo apt-get install lcov
}

main
