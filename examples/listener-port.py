import socket
import sys
import logging

logging.basicConfig(level=logging.INFO)

HOST = "127.0.0.1"
PORT = int(sys.argv[1])

def main():
    socket_conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    socket_conn.bind((HOST, PORT))
    socket_conn.listen(1)
    count = 0

    while True:
        con, _ = socket_conn.accept()
        payload = con.recv(1024)
        print(payload.decode('utf-8'))
        count += 1
        print(count)


if __name__ == "__main__":
    main()
