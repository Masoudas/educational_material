"""
To add WSGI middleware to your Flask application, wrap the application’s wsgi_app attribute. For example, to apply 
Werkzeug’s ProxyFix middleware for running behind Nginx:

from werkzeug.middleware.proxy_fix import ProxyFix
app.wsgi_app = ProxyFix(app.wsgi_app)

Wrapping app.wsgi_app instead of app means that app still points at your Flask application, not at the middleware, 
so you can continue to use and configure app directly.
"""