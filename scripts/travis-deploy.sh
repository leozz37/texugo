#!/bin/bash

# login DockerHub
docker login --username $"DOCKER_HUB_USER" --password $"DOCKER_HUB_PASS"

# Push Dockerfile to DockerHub
cd $"TRAVIS_BUILD_DIR"/docker || exit
docker-compose build --pull
docker-compose push