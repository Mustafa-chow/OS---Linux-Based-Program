#!/bin/bash

echo "Enter a filename:"
read input
echo


if [ -s $input ];    		#checking whether file is in directorey or not
then
	while read line; do
		echo "${line}"
		echo
		echo		# Printing double space after each line
	done < $input
	
else
	echo "File: [${input}] doesn't exist" 
	echo
	
fi








