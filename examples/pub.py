import zmq
import json
import sys

context = zmq.Context()
socket = context.socket(zmq.REQ)
socket.connect("tcp://127.0.0.1:5555")

payload = {
    "recipient" : ["AAAAAAA"],
    "originator" : "CCCCCCC",
    "content" : sys.argv[1]
}

socket.send_json(payload)
message = socket.recv()
print("Received reply[ %s ]" % (message.decode("utf-8")))
