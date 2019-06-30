#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <sstream>

using namespace std;

int anncestors(int p);

int main()
{
	// getting parent pid
	int pid = getpid();

	cout<<"Given process pid: "<< pid << endl;

	//creating location /proc/$PID/status
	
	//converting pid to string
	stringstream process;
	process << pid;
	string pro = process.str();

	// concatinating string to make location
	string location = "/proc/" + pro +"/status";

	//cout<<"Parent process pid of a given process pid can be found in: "<< location <<endl <<endl;

	// creating cat command
	string str = "cat ";
	
	str = str + location;

	const char* cat_command = str.c_str();

	// cat /proc/$PID/status, showing all the information
	system(cat_command);
	
	cout<<"\n--------------------------------------"<<endl;

	// checking PPID of all anncessteor at proc/$PID/stat 

	cout<<"Below is the list of anncestors: "<<endl;
	while(pid != 0)
	{
		cout << "Parent process ID: " << pid << endl;
		pid = anncestors(pid);

	}
	return 0;
}

int anncestors(int p)
{
	int newPPID;
	
	// converting Pid to string
	stringstream process;
	process << p;
	string pro = process.str();
	// concatining string 
	string ppid_location = "/proc/" + pro +"/stat";

	FILE *anncestors;
	anncestors = fopen(ppid_location.c_str(),"r");

	// in linux man page 
	// 		%d = pid, %s=comm %c=stat %d = ppid
	// so, I knew the last %d is PPID, thats why I ignore pid,comm,stat
	// read input from the stream pointer
	fscanf(anncestors,"%*d %*s %*c %d", &newPPID);
	fclose(anncestors);

	return newPPID;
}