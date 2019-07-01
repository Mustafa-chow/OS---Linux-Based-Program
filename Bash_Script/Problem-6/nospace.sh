#!/bin/bash

echo "Enter a filename: "
read input			#read the user input
echo

if [ -s $input ]; then		#checking the filename exist or not

	while read line; do
	    if [[ "$line" == '' ]]; then	
		continue			#skip the exuction if there is empty line
	    fi
	    echo "$line"

	done <"$input"
	
else
	echo "File: [${input}] doesn't exist"
fi
