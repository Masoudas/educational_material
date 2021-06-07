# Ruby does not have multiple inheritance. Modules however can be included inside classes, through a feature called a mixin. 
# Notice here that module methods are not prefixed with module names. This is because, when included in a class, they're bound to that class
# Hence, they don't need to be prefixed.

module Martial_Arts
    def kung_fu
        puts "Doing kung fu"
    end
end

class Person
    include Martial_Arts
end

class Panda
    include Martial_Arts
end

p = Panda.new
n = Person.new

p.kung_fu
n.kung_fu