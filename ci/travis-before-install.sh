#!/usr/bin/env bash

if [ "$IS_COVERAGE_BUILD" == 1 ] && [ "$COVERITY_SCAN_BRANCH" != 1 ]; then
  pip install --user cpp-coveralls
fi