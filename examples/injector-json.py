import socket
import sys
import json
import logging

logging.basicConfig(level=logging.INFO)

HOST = "127.0.0.1"
PORT = int(sys.argv[1])

def main():
    socket_conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    payload = {
        "destination": [sys.argv[2]],
        "message": sys.argv[3]
    }

    try:
        socket_conn.connect((HOST, PORT))
        socket_conn.sendall(bytes(json.dumps(payload), 'utf-8'))
        data = socket_conn.recv(1024)
        logging.info(f'Received: ', data.decode('utf-8'))

        socket_conn.close()

    except Exception as e:
        logging.error(e)

if __name__ == "__main__":
    main()
