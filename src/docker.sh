#!/bin/bash

rm -rf build/*
docker build . -t gen_rfl

