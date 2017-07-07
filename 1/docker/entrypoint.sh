#!/bin/bash
set -e

export MAKEFLAGS

if [[ "$*" ]] ; then
    su student -c "$*"
else
    su - student
fi
