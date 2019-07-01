#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <fstream>

using namespace std;
void writeF(int num)
{
	ofstream w("#ofChild.txt");
	w << num;
	w.close();
}

int main()
{
	
	pid_t pid;
	int count_childProcess= 0;
	while (true)
	{
		pid = fork();
		

		if (pid == 0)
		{
			count_childProcess++;
			cout<<"# of child: "<<count_childProcess<<endl;
			writeF(count_childProcess);
			cout<<"Child process id: "<<getpid()<<endl;
			
		}
		else if (pid>0)
		{
			
			//cout<<"Parent process wainting to finish child"<<endl;
			waitpid(pid, NULL, 0);
			//cout << "The maximum number of child process"<< count_childProcess << endl;
		}
		else
		{
			cout<<"Error"<<endl;
			return -1;
		}


	}
	return 0;
}