#!/usr/bin/env bash
doxygen
git add .
git commit -am "$@"
git push origin master
