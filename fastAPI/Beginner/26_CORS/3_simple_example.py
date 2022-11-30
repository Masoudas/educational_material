"""
So, let's say you have a frontend running in your browser at http://localhost:8080, and its JavaScript is trying to communicate with a backend running at http://localhost (because we don't specify a port, the browser will assume the default port 80).

Then, the browser will send an HTTP OPTIONS request to the backend, and if the backend sends the appropriate headers authorizing the communication from this different origin (http://localhost:8080) then the browser will let the JavaScript in the frontend send its request to the backend. To achieve this, the backend must have a list of "allowed origins".

In this case, it would have to include http://localhost:8080 for the frontend to work correctly.

ME: It's weird. The front-end asks (from port 8080) whether it's allowed to send a request. The backend then says Ok, you're allowed to send requests to me! So, the backend app is the one that sets the CORS policy. But the frontend is where we check for it!
"""
