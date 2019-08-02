// Mustafa Chowdhury, ge3306
#include <iostream>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void action(int sig)
{
	// switching process
	//cout<<"switching"<<endl;
}

void terminate(int sig)
{
	// exiting signal
	cout<<"\nChild process killed by parent"<<endl;
	exit(0);
}

int main()
{
	int count =0;
	int sec, i=0;
	cout<<"\nEntre number of second: ";
	cin >> sec;
	cout<<endl;

	int pid = fork();

	if (pid == 0) // child
	{
		
		// getting signal to quit
		signal(SIGQUIT, terminate);
		while (true)
		{

			signal(SIGUSR1, action); // getting signal from parent
			pause();
			
			cout<<"hello "<< i <<endl;
			i++;	
		}	
	}

	else if (pid > 0) // parent
	{
		while(count <= sec)
		{
			
			sleep(1);
			
			//
			// sending signal to child
			kill(pid, SIGUSR1);
			
			count++;				

			// if count becomes greater than sec than 
			// parent send signal to child to terminate child process
			if (count > sec)
			{
				kill(pid, SIGQUIT);
			}
		}
		
	}

	
	else
	{
		cout<<"Error"<<endl;
		return -1;
	}

	return 0;
}