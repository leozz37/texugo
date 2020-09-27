import json
import socket
import sys
import logging

logging.basicConfig(level=logging.INFO)

HOST = "127.0.0.1"
PORT = int(sys.argv[1])


def main():
    socket_conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    payload = {
        "destination": sys.argv[2],
        "message": sys.argv[3]
    }

    message = bytes(json.dumps(payload), 'utf-8')

    try:
        socket_conn.connect((HOST, PORT))

    except Exception as e:
        logging.error(e)

    while True:
        socket_conn.sendall(message)
        data = socket_conn.recv(1024)
        logging.info('Received: ' + data.decode('utf-8'))


if __name__ == "__main__":
    main()
