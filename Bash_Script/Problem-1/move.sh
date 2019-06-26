#!/bin/bash
# Mustafa ge3306


input=(*.PDF)
echo "Locking for .PDF files ..."
echo
find /$(pwd)/ -name "*.PDF"


# enabling dotglob to change the hidden file
shopt -s dotglob 
if [ -f $input ];    		#checking whether file is in directorey or not
then
	
	echo
	for ext in *.PDF; do
		
		mv "$ext" "${ext%.*}.pdf"
	done
	# disabling dotglob after changed the hidden file
	shopt -u dotglob
	echo "Successfully changed extention from .PDF to .pdf"

else
	echo "${input} doesn't exist in [$PWD] directory"

fi

