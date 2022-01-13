"""
If a response contains some Cookies, you can quickly access them:

To send your own cookies to the server, you can use the cookies parameter:

Cookies are returned in a RequestsCookieJar, which acts like a dict but also offers a more complete interface, suitable for use over multiple domains or paths. Cookie jars can also be passed in to requests:
"""
import requests 

url = 'http://example.com/some/cookie/setting/url'
r = requests.get(url)

r.cookies['example_cookie_name']
'example_cookie_value'

# Send cookies
url = 'https://httpbin.org/cookies'
cookies = dict(cookies_are='working')

r = requests.get(url, cookies=cookies)
r.text
'{"cookies": {"cookies_are": "working"}}'


# Using cookie jars
jar = requests.cookies.RequestsCookieJar()
jar.set('tasty_cookie', 'yum', domain='httpbin.org', path='/cookies')
jar.set('gross_cookie', 'blech', domain='httpbin.org', path='/elsewhere')

url = 'https://httpbin.org/cookies'
r = requests.get(url, cookies=jar)
r.text
'{"cookies": {"tasty_cookie": "yum"}}'
