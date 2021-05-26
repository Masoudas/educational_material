# Classes start with class and end with end. They should be lined up
class Apple
    attr_accessor :color, :flavor   # accessor methods as well
    def eat
        puts "Eaten"
    end
    
    def print(x)
        puts x
    end

    # Notice how we access the class fields
    def printAppleType()
        puts "The apple is a #{@color} apple with #{@flavor}"
    end

    # If a function has no explicit return statement, the last expression calculated or defined is returned!
    def returnVal()
        return 1
    end

    def return_last_expression()
        x = 10
        x = x ** 2  # Power
        x + 10  # Returns this!
    end
end

def comma_joiner(input_arry)
    input_str.join(",") # Returns this.
end

gala = Apple.new    # The new method should be used.
gala.color = "red"
gala.flavor = "sweet"

# To call methods, we can use paranthesis or not
gala.eat
gala.print("Apple")
gala.print "Orange"

puts gala.returnVal
gala.printAppleType
# Apparently everything in Ruby is a class. Hence for example 10.instance_of?(Integer) returns true.
# Note that any method that returns a boolean value has a name that ends in a question mark.
# instance_of returns a boolean. Hence, it has a question mark method. Any class name we give as an argument is evaluated, and compared with the variable
# I guess.

# We cam check the class type of a variable by writing .class
puts "hi".class