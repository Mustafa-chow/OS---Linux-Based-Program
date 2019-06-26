#!/bin/bash
# Mustafa Chowdhury, ge3306
PS1="Default"
var=$PS1
his=""
in=""
ignore=""

#echo "$var> Enter a command: "
while :; 
do
	printf "$var$ "
	read input input2
	

	case $input in

		prompt)
			# if 2nd input is null then error
			if [ -z "$input2" ]; then
				echo "error, prompt [type anything]"
				echo
			else
				var=$input2
				his="$his $input"
			fi
		

			;;

		hour)
			
			printf "Tuesday 5.30 PM - 6.45 PM and Thursday 5.30 PM - 6.45 PM \n"
			echo
			his="$his $input"
			
			;;

		room)
			printf "ATEC 150\n"
			echo
			his="$his $input"

			;;

		desp)

			echo "Course Description:"
			printf "\tOperating system is an essential software layer to use various computing devices.\n"
			printf "\tThis course covers the basic components and design principles of modern operating systems,\n"
			printf "\tincluding process and thread, CPU scheduling, memory management, file system and others.\n"
			printf "\tThis course also provides hand-on programming experiences of using Linux system calls, \n"
			printf "\tand design and implementation of a cloud-based file system.\n"
			echo
			his="$his $input"


			
			;;

		text)
		
			echo "Textbook:"
			printf "\tModern Operating Systems, Andrew S. Tanenbaum, 4th Edition, Pearson, 2015"
			echo
			his="$his $input"
	
			
			;;

		ref)
			
			echo "Referrence Book: "
			printf "\tperating System Concepts, 8th Edition, Wiley, 2008.\n"
	    		printf "\tUnderstanding the Linux Kernel, 3rd Edition, O'Reilly Media, 2005.\n"
	    		printf "\tAdvanced UNIX Programming, 2nd Edition, Pearson, 2004.\n"
	    		printf "\tAdvanced Programming in the UNIX Environment, Addison-Wesley, 1992.\n"
	    		echo
	    		his="$his $input"
			
	    		;;

    	prof)
			
    		echo "Professor: Kamal Nayfeh"
    		echo	
    	
    		;;

    	pol)
			
			echo "Office location: ATECH 150"
			echo
			his="$his $input"
		
		;;
		pma)
				
			echo "Professor email: knayfeh@wayne.edu"
			echo
			his="$his $input"
			
			;;

		poh)
			
			echo "Office hours: 6.45 PM - 7.15 PM or by appointment"
			echo
			his="$his $input"
			
			;;

		pre)

			echo "Prerequisites: CSC 3100/3101 and CSC 2200/2201"
			echo
			his="$his $input"
			;;

		cor)
				
			echo "Co-requisite: CSC 4421 Lab"
			echo
			his="$his $input"
				
			;;

		hw)
			
			hwork="Homework(1) Homework(2) Homework(3) Homework(4) Project"
			count=0
			for i in $hwork; do
				count=$((count+1))
				echo "$count. $i"
			done
			echo
			his="$his $input"
			
			;;
		gr)
			
				echo "Homework 50% and Project 50%"
				echo
				his="$his $input"
			
			;;

		history)
		
			#convert string to integer
			eventNum=$(expr "$input2")
			count=0
			for i in $his;do
				

				his="$i $his"
			done
			for j in $his; do
				if [ $eventNum -eq 0 ];
				then
					break
				fi
				count=$((count+1))
				echo "($count) $j"
				if [ $count -eq $eventNum ];
				then
					break
				fi
			done
			his="$his $input"
			
			echo
			;;

		help)
		
			echo
			printf  "\tprompt: Set your own promt\n"
			printf "\thour : list class times\n"
			printf "\troom : list classroom location\n"
			printf "\tdesp : list the description of this course\n"
			printf "\ttext : list the textbook\n"
			printf "\tref : list the reference books \n"
			printf "\tprof : list the professor's name\n"
			printf "\tpol : professor's office location\n"
			printf "\tpoh : professor's office hours\n"
			printf "\tpre : list the course pre-requisites\n"
			printf "\tcor : list the course co-requisite\n"
			printf "\thw: list the number of home works\n"
			printf "\tgr : list the grading policy \n"
			printf "\thistory : list history of events\n"
			printf "\tthelp : list all the available commands\n"
			printf "\texit or quit : exit CSC4420 shell\n"
			echo
			his="$his $input"
			
			;;	

		exit | quit)
			echo "Exiting..."
			exit 1
			;;
		*)
			echo "Invalid entry!!"
			echo
		;;
			
	esac

done