import json
import requests
import sys
import time
import zmq
import sys
from random import randint

context = zmq.Context()
socket = context.socket(zmq.REQ)
socket.connect("tcp://127.0.0.1:" + sys.argv[1])

api_url = "https://random-word-api.herokuapp.com/key?"

def generate_random_word():
    req = requests.get(api_url)
    print(req.text)
    return req.text

def pub_word():
    while (1):
        payload = {
            "recipient" : sys.argv[2],
            "originator" : "CCCCCCC",
            "content" : generate_random_word()
        }
        socket.send_json(payload)
        time.sleep(1)
        message = socket.recv()
        print("Received reply[ %s ]" % (message.decode("utf-8")))

if __name__ == "__main__":
    pub_word()
