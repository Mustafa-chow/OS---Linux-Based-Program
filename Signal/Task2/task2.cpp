// Mustafa Chowdhury, ge3306
#include <iostream>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>

using namespace std;

void action(int sig)
{
	//switching process
	//cout<<"Switching";
}

// writing output
void writeOutput(string s, int num)
{
  ofstream write("output.txt",ios::app);//appending it
  write<<s<<num <<"\n";
  write.close();
}

// write into number.txt
void writeF(int num)
{
	ofstream w("number.txt", ofstream::out | ofstream::trunc);
	w << num;
	w.close();
}

// read from number.txt
int readN()
{
	ifstream read;
	int num;
	read.open("number.txt");
	read >> num;
	read.close();
	return num;
}

// updating value by child
void child()
{
	int x = readN();
	x = x/5;
	writeF(x);
	cout<<"Child: x = "<<x<<endl;
	writeOutput("Child: x = ", x);
}

//updating value by parent
void parent()
{
	int x = readN();
	x = x -5;
	writeF(x);

	cout<<"Parent: x = "<<x<<endl;
	writeOutput("Parent: x = ", x);
}

int main()
{
	int x = 19530;
	cout <<"X = "<< x << endl;
	writeF(x);
	writeOutput("X = ", x);

	int i;
	pid_t pid = fork();

	if (pid == 0) // child
	{
		
		for (i = 1; i<=5; i++)
		{
			// getting signal from parent
			signal(SIGUSR1, action);
			pause();
			
			child();

			// send signal to parent
			kill(getpid(),SIGUSR1);
		}
	
	}
	else if (pid > 0)//parent
	{
		sleep(1);
		
		for (i = 1; i<=5; i++)
		{
			cout<<"\nITERATION "<< i <<endl;
			writeOutput("\nITERATION ", i);

			// geting signal from child
			signal(SIGUSR1, action);

			parent();

			// sending signal to child
			kill(pid, SIGUSR1);	

			sleep(1);
		}
	}
	else
	{
		cout<<"Error"<<endl;
		return -1;
	}
	
	remove("number.txt");
	return 0;
}