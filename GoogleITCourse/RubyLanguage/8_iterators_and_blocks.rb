# The most famous example of iterator we've seen is the times method.

5.times do
    puts "Here"
end

1.upto(5) { |number| puts "#{number}"}  # Inclusive range
5.downto(5) { |number| puts "#{number}"}    # Inclusive range
'a'.upto('e') { |char| puts "#{char}" }

5.times do |iteration|
    puts "#{iteration}th iteration"
end

[1, 2, 3, 4, 5].each() { |number| puts "#{number}"}