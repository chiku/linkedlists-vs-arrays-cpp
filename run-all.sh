#!/bin/sh

mkdir -p output

cd arraylist
make clean compile test
./bin/arraylist | tee ../output/arraylist.csv
cd ..

cd linkedlist
make clean compile test
./bin/linkedlist | tee ../output/linkedlist.csv
cd ..

ruby generate_chart_report.rb
ruby generate_spreadsheet_report.rb
