require "csv"
require "axlsx"

sample_to_times = {}

CSV.foreach("output/arraylist.csv") do |(sample_size, time)|
  sample_to_times[sample_size.to_f] = [time.to_f]
end

CSV.foreach("output/linkedlist.csv") do |(sample_size, time)|
  sample_to_times[sample_size.to_f] << time.to_f
end

size = sample_to_times.size

Axlsx::Package.new(:author => "Chirantan") do |p|
  p.workbook.add_worksheet(:name => "Arrays vs Linked-list") do |sheet|
    sheet.add_row ["List size", "Array (ms)", "Linked-list (ms)"]
    sample_to_times.each do |size, (array, linked_list)|
      sheet.add_row [size, array, linked_list]
    end

    sheet.add_chart(Axlsx::ScatterChart, :title => "Arrays vs Linked-list", :scatter_style => :smooth) do |chart|
      chart.start_at 3, 1
      chart.end_at 14, 25
      chart.add_series :xData => sheet["A2:A#{1+size}"], :yData => sheet["B2:B#{1+size}"], :title => "Array", :color => "FF0000"
      chart.add_series :xData => sheet["A2:A#{1+size}"], :yData => sheet["C2:C#{1+size}"], :title => "Linked-list", :color => "00FF00"
    end
  end

  p.serialize("report.xlsx")
end
