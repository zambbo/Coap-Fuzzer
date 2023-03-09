#!/bin/bash

filename=$1

filename="${filename%.c}"

clang -fsanitize=fuzzer,address -I/home/libcoap/include -L/home/libcoap/.libs -lcoap-3 -o $filename $1
