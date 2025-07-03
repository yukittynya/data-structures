#!/bin/bash

if [ "$#" -ne 1 ]; then 
    echo "USAGE: ./make.sh <data-structure>"
    exit 1
fi

files=""
for file in "src/$@/"*.c; do
 files+="${file} "
done

gcc -O0 ${files} -o $@ 
./$@
