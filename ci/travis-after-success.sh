#!/usr/bin/env bash

if [ "$IS_COVERAGE_BUILD" == 1 ] && [ "$COVERITY_SCAN_BRANCH" != 1 ]; then
  coveralls --exclude lib --exclude tests --gcov-options '\-lp'
fi