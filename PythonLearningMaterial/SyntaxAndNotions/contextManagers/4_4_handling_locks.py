"""
With locks, because there's need for releasing the lock at the end, context managers are quite handy as well:

import threading

balance_lock = threading.Lock()

# Use the try ... finally pattern
balance_lock.acquire()
try:
    # Update the account balance here ...
finally:
    balance_lock.release()

# Use the with pattern
with balance_lock:
    # Update the account balance here ...
    
"""
