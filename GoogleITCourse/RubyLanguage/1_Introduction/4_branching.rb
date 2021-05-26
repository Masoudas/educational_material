puts "How old are you?"

age = gets.chomp    # gets from terminal. Direct gets has the '\n' at the end, and chomp chops of that

# When a language does not use curly braces, it needs end for terminating end and for!
if age.to_i < 18
    puts "Not eligible to vote"
end

# Nil is a nothing or void in Ruby
val = "String val"
val2 = nil
if some_value && !val2
    puts "we're here"
elsif some_value
    puts "Only string is valod"
end