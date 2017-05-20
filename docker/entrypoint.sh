#!/bin/bash
set -e

if [[ "$*" ]] ; then
    cd /home/student
    su - student -c "$*"
else
    su - student
fi
