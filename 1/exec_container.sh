#!/bin/bash
echo "######################################################"
echo "This script will fail if the cointainer is not started"
echo -e  "######################################################\n"
docker exec -ti `docker ps -q` bash
