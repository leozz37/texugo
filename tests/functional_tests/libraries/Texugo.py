#!/usr/bin/env python2
import docker


class Texugo:
    def run_texugo(self):
        client = docker.from_env()
        self.texugo_container = client.containers.run('texugo', network='host', detach=True)

    def kill_texugo(self):
        self.texugo_container.kill()
