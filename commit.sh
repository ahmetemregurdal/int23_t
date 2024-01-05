#!/usr/bin/env bash
doxygen
git commit -am "$@"
git push origin master
