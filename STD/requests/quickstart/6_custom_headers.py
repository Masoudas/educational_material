"""
If you'd like to add HTTP headers to a request, simply pass in a dict to the headers parameter.
For example, we didn't specify our user-agent in the previous examples:

Note: Custom headers are given less precedence than more specific sources of information. For instance:
    -   Authorization headers set with headers= will be overridden if credentials are specified in .netrc, which in turn will be overridden by the auth= parameter. Requests will search for the netrc file at ~/.netrc, ~/_netrc, or at the path specified by the NETRC environment variable.

    -   Authorization headers will be removed if you get redirected off-host.

    -   Proxy-Authorization headers will be overridden by proxy credentials provided in the URL.

    -   Content-Length headers will be overridden when we can determine the length of the content.

    -   Furthermore, Requests does not change its behavior at all based on which custom headers are specified. The headers are simply passed on into the final request.

Note: All header values must be a string, bytestring, or unicode. While permitted, it's advised to avoid passing unicode header values.
"""
import requests

url = 'https://api.github.com/some/endpoint'
headers = {'user-agent': 'my-app/0.0.1'}

r = requests.get(url, headers=headers)
