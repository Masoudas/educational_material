# An explicit array instantiation
x = ["a", "b", "c", 1]
puts x.class

puts x[3]

puts x[4]   # Prints nill

x.each do |word|
    puts "#{word}!" # String interpolation. Everything between the hash and brackets gets evaluated.
end

puts x[1] + "#{1 + 1}" + x[2];

x.push("Here")  # Push elements to the end of the array
puts w = x.pop()

#x.sort();

puts x.length()
puts x.last()
