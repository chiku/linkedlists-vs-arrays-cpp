#!/bin/sh

mkdir -p outputs

cd arraylist
make clean compile test
./bin/arraylist | tee ../outputs/arraylist.csv
cd ..

cd linklist
make clean compile test
./bin/linklist | tee ../outputs/linklist.csv
cd ..

ruby generate_chart_report.rb
ruby generate_spreadsheet_report.rb
