from flask import Flask,render_template, request,redirect,url_for
from flak_sqlalchemy import SQLAlchemy
import os

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite://quiz.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS']= False 

db=SQLAlchemy(app)

#Models

class User(db.Model):
    id = db.Column(db.Integer, pretinary_key=True)
    username= db.Column(db.String(80), Unique=True, nullable=False)

#Add new user-related fields as needed

class Question(db.Madel):
    id =db.Column(db.Integer, primary_key=True) 
    content= db.Column(db.String(500), nullable=False)
    question_type= db.Column(db.String(20), nullable =False)

#Add more question related fields as needed

class Answer (db.Model):

    id =db.Column(db.Integer, primary_key=True)
    user_id= db.Column(db.Integer, db.Foreignkey("userId"), nullable= False)
    question_id = db.Column(db.Integer, dh.Foreignkey('question.id'), nullable=False) 
    answer_content =db.Column(db.String(100), nullable=False)

#Add more answer-related fields as needed

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/')
def index():
    return render_template('index.html')
if __name__=='__main__':
    with app.app_context():
        db.create_all()
    app.run(debug-True)
