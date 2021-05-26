# We have logical &&, || and !. ! has higher precende than &&, which is higher than ||.
puts false || true && !true  # Evaluates to false

# We also have, or, and and not. These have lower precedence than &&, ||, and !. These are normaly used to control the flow of
# of the program.
isTired = true
wantCoffee = true
if isTired and wantCoffee
    puts "Go away!"
end