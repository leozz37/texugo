import socket
import sys

host = "127.0.0.1"
port = int(sys.argv[1])
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host, port))

while 1:
    s.sendall(b'Hello, world')
    data = s.recv(1024)
    print('Received:', data.decode('utf-8'))
