# The keyword modules is used for defining modules in ruby. Apparently module names must start with capital. Access module elements with the
# dot operator.
# Module constants are named just like class constants, with an initial uppercase letter. The method definitions look similar, too: Module 
# methods are defined just like class methods.
# Notice that method names are preceded with module name.
# Then, we also define a class inside a module as shown below!

def myMethod
    return nil
end

module Amodule
    def Amodule.myMethod()
        return nil  
    end

    class AClass
        def AClass.aClassMethod
            return nil
        end
    end
end

myMethod
Amodule.myMethod()
Amodule::AClass::aClassMethod