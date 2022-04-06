"""
Requests makes it simple to upload Multipart-encoded files:

"""
import requests

url = 'https://httpbin.org/post'
files = {'file': open('report.xls', 'rb')}

r = requests.post(url, files=files)
print(r.text)
# {
#    ...
#    "files": {
#        "file": "<censored...binary...data>"
#    },
#    ...
# }

# You can set the filename, content_type and headers explicitly:
files = {'file': ('report.xls', open('report.xls', 'rb'),
                  'application/vnd.ms-excel', {'Expires': '0'})}
r = requests.post(url, files=files)

# We may also ask strings to be recieved as files:
files = {'file': ('report.csv', 'some,data,to,send\nanother,row,to,send\n')}
r = requests.post(url, files=files)
