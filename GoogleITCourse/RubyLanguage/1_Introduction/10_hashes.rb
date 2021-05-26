# Associative arrays
x = {}

puts x.class

y = {"a"=>1, "b"=>2, "c"=>3}

puts y["a"]

y.each() do |k,v|
    puts "#{k} + #{v}"
end

y["a"] = 10

y.delete("a")