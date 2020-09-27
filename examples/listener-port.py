import socket
import sys
import logging

logging.basicConfig(level=logging.INFO)

HOST = "127.0.0.1"
PORT = int(sys.argv[1])


def main():
    socket_conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        socket_conn.connect((HOST, PORT))

    except Exception as e:
        logging.error(e)

    while True:
        payload = socket_conn.recv()
        message = payload.decode('utf-8')
        print(message)

if __name__ == "__main__":
    main()
