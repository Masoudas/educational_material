"""
	-	stat: Print file status (use datetime.fromtimestamp method to change times in stat. See example below.)
	-	create files: Recall that open method actually can create files with the w keys. So, don't look
		for any methods here :D.
"""

from os import stat
from datetime import datetime

mod_time_in_s = stat("./STD/os/2_file_methods.py").st_mtime

print(datetime.fromtimestamp(mod_time_in_s))

with open("file.txt", "w") as f:
	f.write("Hey")

