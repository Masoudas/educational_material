# Classes start with class and end with end. They should be lined up
class Apple
    attr_accessor :color, :flavor   # accessor methods as well
end

gala = Apple.new    # The new method should be used.
gala.color = "red"
gala.flavor = "sweet"

# Apparently everything in Ruby is a class. Hence for example 10.instance_of?(Integer) returns true.
# Note that any method that returns a boolean value has a name that ends in a question mark.
# instance_of returns a boolean. Hence, it has a question mark method. Any class name we give as an argument is evaluated, and compared with the variable
# I guess.

# We cam check the class type of a variable by writing .class
puts "hi".class