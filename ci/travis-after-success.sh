#!/usr/bin/env bash

if [ "$IS_COVERAGE_BUILD" == 1 ] && [ "$COVERITY_SCAN_BRANCH" != 1 ]; then
  coveralls -e deps -e examples --gcov-options '\-lp'
fi