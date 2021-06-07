# Consider the net/http standard library of ruby. We use it to download the google homepage, and print it on the screen (in html!)

require "net/http"

puts Net::HTTP.get("www.google.com", "/")