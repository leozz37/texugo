#!/usr/bin/env python3
import json
import queue
import socket
import threading

host = "127.0.0.1"


class SocketInjector:
    def verify_message(self, port1, port2, message, destination):
        q = queue.Queue()
        threading.Thread(target=open_connection, args=(port1, q)).start()

        send_message(port2, message, destination)
        return q.get()


def open_connection(port, q):
    socket_conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket_conn.bind((host, port))
    socket_conn.listen(1)

    con, _ = socket_conn.accept()
    payload = con.recv(1024)
    message = payload.decode('utf-8')
    q.put(message)


def send_message(port, message, destination):
    socket_conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    payload = {
        "destination": destination,
        "message": message
    }

    dumped_message = bytes(json.dumps(payload), 'utf-8')

    socket_conn.connect((host, port))
    socket_conn.sendall(dumped_message)


if __name__ == '__main__':
    injector = SocketInjector()
    print(injector.verify_message(3005, 3001, "test", "ENDPOINT"))
