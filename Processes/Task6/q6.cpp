#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>

using namespace std;
void action(int sig)
{
	// switching process
	//cout<<"switching"<<endl;
}

void terminate(int sig)
{
	// exiting signal
	//cout<<"Child killed "<<endl;
	exit(0);
}

int main()
{
	int i=0, iter = 5;
	int count = 0;

	clock_t start = clock();
	clock_t end;

	//cout<< "Before processing start, CUP time is: "<<double(start)/CLOCKS_PER_SEC<<endl<<endl;

	double totalTime = 0.0;

	int pid = fork();

	if (pid == 0) // child
	{
		
		//getting signal to quit
		signal(SIGQUIT, terminate);
		while (true)
		{

			signal(SIGUSR1, action); // getting signal from parent
			pause();
			
			cout<<"Child Process Running.. "<< i <<endl;
			i++;
			//kill(getpid(), SIGUSR1);	
		}	
	}

	else if (pid > 0) // parent
	{
		while(count <= iter)
		{
			sleep(1);
			count++;				
			
			// if count becomes greater than sec than 
			// parent send signal to child to terminate child process
			if (count > iter)
			{
				kill(pid, SIGQUIT);
			}
			else
			{
				cout<<"Parent send signal to child"<<endl;
			// sending signal to child
				kill(pid, SIGUSR1);	
			}
		}
	}
	else
	{
		cout<<"Error"<<endl;
		return -1;
	}
	end = clock();

	//cout<<"\nAfter process end, current CPU time is: "<<double(end)/CLOCKS_PER_SEC<<endl;

	totalTime = (double(end - start)/CLOCKS_PER_SEC);

	cout<<"\nTotal time needed to complete the processes by CPU is: "<<totalTime<<endl;


	return 0;
}