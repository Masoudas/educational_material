"""
It's possible to respond with a json directly, or convert objects to json, as the following example demonstrates.

flask also provides a helper jsnofy function, which can be used to jsonify jsonifiable objects.
"""	
from flask import Flask

app = Flask(__name__)

@app.route("/")
def main():
	user = get_current_user()
	return {
        "username": user.username,
        "theme": user.theme,
        "image": url_for("user_image", filename=user.image),
    }

@app.route("/users")
def users_api():
    users = get_all_users()
    return jsonify([user.to_json() for user in users])