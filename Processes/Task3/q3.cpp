#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

int main()
{
	cout<<"Pareent id before: "<<getppid()<<endl;
	pid_t pid = fork();
	
	if (pid == 0)
	{
		cout<<"\nInside Child process"<<endl;
		cout<<"Exting child process..."<<endl;
		return -1;
		
	}
	if (pid >0)
	{
		sleep(1);
		
	}
	cout<<"\nparent id after: "<<getppid()<<endl<<endl;
	
	return 0;
}