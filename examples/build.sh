#!/bin/bash

docker run  -u $(id -u):$(id -g)  -it -v .:/root gen_rfl gen_rfl