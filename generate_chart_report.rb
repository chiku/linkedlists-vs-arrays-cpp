require "csv"
require "erb"

sizes = []
arrays = []
linked_lists = []

CSV.foreach("output/arraylist.csv") do |(sample_size, time)|
  sizes << sample_size.to_f
  arrays <<  time.to_f
end

CSV.foreach("output/linkedlist.csv") do |(sample_size, time)|
  linked_lists << time.to_f
end

container_sizes = sizes.join(", ")
array_durations = arrays.join(", ")
linked_list_durations = linked_lists.join(", ")
b = binding
result = ERB.new(File.read("public/comparison.js.erb")).result b

File.open("public/comparison.js", "w") { |f| f << result }
