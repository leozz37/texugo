import time
import zmq
import sys

port = sys.argv[1]

context = zmq.Context()
socket = context.socket(zmq.SUB)
socket.setsockopt(zmq.SUBSCRIBE, b"")

socket.connect("tcp://127.0.0.1:" + port)

while True:
    #  Wait for next request from client
    payload = socket.recv()
    message = payload.decode("utf-8")
    print("[" + port + "] request - %s" % message)

    