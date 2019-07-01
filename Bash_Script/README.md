Problem #1
-------------
Write a simple shell script to move (rename) all *.PDF files under the current 
directory (if any) to *.pdf, e.g., 
move 
test.PDF 
to 
test.pdf 
move 
hello.PDF.PDF 
to 
hello.PDF.pdf
move .
hello.PDF.PDF 
to 
.hello.PDF.pdf 
and report each action, otherwise just report there are no *.PDF files. 

Problem #2
--------------
Write a shell script “
CSC4420 shell”
, to support at least the following built-in 
commands: 
o
    prompt 
can set to any string you input, in addition to the current history event 
number, i.e, %h as in csh; 
o
    hour 
: list class times 
o
    room 
: list classroom location 
o
    desp 
: list the description of this course 
o
    text 
: list the textbook 
o
    ref 
: list the reference books 
o
    prof 
: list the professor's name 
o
    pol 
: professor's office location 
o
    poh 
: professor's office hours 
o
    pma 
: professor's email address 
o
    pre 
: list the course pre-requisites
o
    cor 
: list the course co-requisite
o
    hw 
: list the number of home works
o
    gr 
: list the grading policy (what percentage for home works, midterm exam, and 
final exam)
o
    history : list history of events up to the number you set 
o
    help : list all the available commands 
o
    exit or quit : exit CSC4420 shell 

Problem #3
--------------
Write a script that backs itself up, that is, copies itself to a file named backup.sh.
Hint: Use the cat command and the appropriate positional parameter.

Problem #4
--------------
Write a script that echoes itself to stdout, but backwards.

Problem #5
--------------
Write  a  script  that  reads  each  line  of  a  target  file,  then  writes  the  line  back  to  stdout,  but  with  an  extra blank line following. 
This has the effect of double-spacing the file.Include  all  necessary  code  to  check  whether  the  script  gets  the  necessary  command-line  argument  (a filename), 
and whether the specified file exists.When the script runs correctly, modify it to triple-space the target file.Finally, 
write a script to remove all blank lines from the target file, single-spacing it.


