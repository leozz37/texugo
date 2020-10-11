#!/usr/bin/env sh

set -e

npm run build
cp CNAME dist/
cd dist

git init
git add -A
git commit -m "🚀 deploy on GitHub Pages"

git push -f git@github.com:leozz37/texugo.git master:gh-pages
cd -