#!/bin/bash

set -e

if [ "$#" -lt 1 ]; then
    echo "Usage: ./$0 <target_dir>"
    exit
fi

file_name=$1
klee --max-time=5min --posix-runtime --libc=uclibc --libcxx --external-calls=all --only-output-states-covering-new=true $file_name A --sym-stdin 128 --sym-files 1 128
