#!/bin/bash

# Mustafa Chowdhury

echo "Enter a filename: "
read input
echo 


if [ -f $input ];			#checking file is exist or not		
then
	while read line; do
		echo "${line}"
		echo			#print double space after each line
		echo
	done < $input
	
else
	echo "File: [${input}] doesn't exist" 
	
fi










