import socket
import sys

host = "127.0.0.1"
port = int(sys.argv[1])

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host, port))

message = {
    "destination": [sys.argv[2]],
    "payload": sys.argv[3]
}

s.sendall(bytes(str(message), 'utf-8'))
data = s.recv(1024)
print('Received:', data.decode('utf-8'))

s.close()
