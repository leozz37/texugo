import socket
import sys
import logging

logging.basicConfig(level=logging.INFO)

HOST = "127.0.0.1"
PORT = int(sys.argv[1])
MESSAGE = bytes(sys.argv[2], 'utf-8')

def main():

    socket_conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        socket_conn.connect((HOST, PORT))
        socket_conn.sendall(MESSAGE)

        data = socket_conn.recv(1024)
        logging.info(f'Received: ', data.decode('utf-8'))
        socket_conn.close()

    except Exception as e:
        logging.error(e)


if __name__ == "__main__":
    main()
