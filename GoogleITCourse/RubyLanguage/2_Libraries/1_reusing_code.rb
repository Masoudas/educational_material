# Require method for including other files is very common. For example, imagine that we have someMethod in someMethod.rb, then we load it as
# follows:
re "./someMethod"   # From current direcory, and .rb is added if needed to it! Otherwise ignored I guess. Add full path or search in $LOAD_PATH
require_relative "anotherScript"    # Look for it in the current directory

# Load method loads the code and reprocesses it inside the current script. require however only imports code once, and processes it once.
# Hence, if there's a print expression in the loaded file, it will be printed twice, once loaded and once executed. 

