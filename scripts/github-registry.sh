#!/bin/bash

#Github Login
echo "${GITHUB_TOKEN}" | docker login docker.pkg.github.com -u "${GITHUB_USER}" --password-stdin

cd "$TRAVIS_BUILD_DIR"/docker || exit
docker-compose build --pull
docker tag docker_texugo docker.pkg.github.com/"${GITHUB_USER}"/texugo/texugo:latest
docker push docker.pkg.github.com/"${GITHUB_USER}"/texugo/texugo:latest
