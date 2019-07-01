#!/bin/bash

newLine=$'\n'

rev=""

for i in $(more $0); do
	rev="$i$newLine$rev"
done


for word in $rev; do
	echo "$word"
done


