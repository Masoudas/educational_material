"""
Normally, we tend to use time.time() to get the start and end point time of a code execution. The better way is
to use perf_counter, which is more accurate than time.
"""
import time

current_time = time.time() # This would actually be the time!

start = time.perf_counter()
start_ns = time.perf_counter_ns()

print("Something")

end = time.perf_counter()
end_ns = time.perf_counter_ns()

end_time = time.time() # This would actually be the time!

print(end_time - current_time)
print(end - start, "Better measure")
print(end_ns - start_ns, "Better measure (ns)")
