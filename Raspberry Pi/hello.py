import json
from flask import jsonify

from flask import Flask, render_template,abort, request
app = Flask(__name__)

@app.route('/')
def hello_world():
	return 'Hello, World!\n'

welcome = "Welcome to 3ESE API!"

@app.route('/api/welcome/', methods=['POST','GET','DELETE'])
def api_welcome():
	global welcome
	if request.method == 'POST':
		welcome = request.get_json()['data']
		return "",202
	if request.method == 'DELETE':
		welcome = ''
		return "",205
	return jsonify({"text":welcome})

@app.route('/api/welcome/<int:index>', methods=['GET','PUT','PATCH','DELETE'])
def api_welcome_index(index):
	global welcome
	if index<len(welcome):
		if request.method == 'GET':
			return jsonify({"index":index, "val":welcome[index]})
		if request.method == 'PUT':
			welcome = welcome[:index]+" "+request.get_json()['data']+" "+welcome[index+1:]
		if request.method == 'DELETE':
			welcome = welcome[:index]+welcome[index+1:]
		if request.method == 'PATCH':
			welcome = welcome[:index]+request.get_json()['data']+welcome[index+1:]
	else:
		abort(404)
	return jsonify(welcome)

@app.route('/api/request/', methods=['GET', 'POST'])
@app.route('/api/request/<path>', methods=['GET','POST'])
def api_request(path=None):
	resp = {
		"method":   request.method,
		"url" :  request.url,
		"path" : path,
		"args": request.args,
		"headers": dict(request.headers),
	}
	if request.method == 'POST':
		resp["POST"] = {
			"data" : request.get_json(),
		}
	return jsonify(resp)

@app.errorhandler(404)
def page_not_found(error):
    return render_template('page_not_found.html'), 404
