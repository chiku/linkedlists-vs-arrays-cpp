#!/bin/sh

mkdir -p outputs

cd arraylist
make clean compile test
./bin/arraylist | tee ../outputs/arraylist.csv
cd ..

cd linkedlist
make clean compile test
./bin/linkedlist | tee ../outputs/linkedlist.csv
cd ..

ruby generate_chart_report.rb
ruby generate_spreadsheet_report.rb
