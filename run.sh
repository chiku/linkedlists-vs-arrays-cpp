#!/bin/sh

set -euo pipefail
IFS=$'\n\t'

main() {
  mkdir -p output
  cd arraylist && ./bin/arraylist | tee ../output/arraylist.csv && cd ..
  cd linkedlist && ./bin/linkedlist | tee ../output/linkedlist.csv && cd ..
  ruby generate_chart_report.rb
  ruby generate_spreadsheet_report.rb
}

main
