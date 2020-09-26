import socket
import sys

host = "127.0.0.1"
port = int(sys.argv[1])
message = bytes(sys.argv[2], 'utf-8')

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host, port))

s.sendall(message)
data = s.recv(1024)
print('Received:', data.decode('utf-8'))

s.close()
