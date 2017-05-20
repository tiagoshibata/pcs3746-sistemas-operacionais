#!/bin/bash
set -ex

fail() {
    echo $1 >&2    
    exit 1
}

NUMBER_OF_ARGUMENTS=$#

LINUX_VOLUME="$PWD/../linux:/home/student/src/linux"
INITRAMFS_VOLUME="$PWD:/home/student/src/initramfs"
VOLUMES="-v $LINUX_VOLUME -v $INITRAMFS_VOLUME"

DEFAULT_COMMAND="docker run $VOLUMES so"
INTERACTIVE_COMMAND="docker run -t $VOLUMES so bash"

if [ $NUMBER_OF_ARGUMENTS -eq 0 ]
then
    echo "Running default program..."
    eval $DEFAULT_COMMAND
    # docker run -v "$PWD"/../linux:/home/student/src/linux -v "$PWD":/home/student/src/initramfs so
else
    if [ $NUMBER_OF_ARGUMENTS -gt 1 ]
    then
        fail "You must supply only one argument, run the command with --help or -h to see the options."
    else
        case $1 in
            -i) echo "Running in interactive"
                eval $INTERACTIVE_COMMAND
                ;;
            -h) echo "help - to be developed"
                ;;
            -d) echo "debug - to be developed"
                ;;
            *) echo "default"
               eval $DEFAULT_COMMAND
                ;;
        esac
    fi
fi