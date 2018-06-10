#!/bin/bash

DOCKER_PS=$(docker ps | grep tiagoshibata | tr -s [:blank:])
DOCKER_COUNT=$(echo $DOCKER_PS | wc -w)
DOCKER_NAME=$(echo $DOCKER_PS | cut -d" " -f$DOCKER_COUNT)

