#!/bin/bash


result="rez.txt"
extension=".txt"

if [ -z "$1" ]; then
    echo 
    exit 1
fi
searching="$1"
for file in *${extension}; do
    if [ -f "$file" ]; then
        grep -q "$searching" "$file" && echo "$file" >> "$result"
    fi
done
