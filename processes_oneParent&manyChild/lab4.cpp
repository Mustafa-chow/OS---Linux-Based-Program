#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fstream>
 using namespace std;

static int count=0;
// writing file to produce output.txt
void w(string s, int num)
{
  ofstream write("output.txt",ios::app);//appending it
  write<<s<<num <<"\n";
  write.close();
}

//write to number.txt
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
void child()
{
	int x = readN()/5;
	writeF(x);
	cout<<"Child is: "<<x<<endl;
	w("Child: x = ", x);
	//exit(EXIT_FAILURE);
}
int parent(int n, int p)
{
	int x = readN();
	x = x -5;
	cout<<"Parent is: "<<x<<endl;
	w("Parent: x = ", x);
	//waitpid(p, NULL, 0);
	writeF(x);
	return x;
}
int main()
{
	// initialize x then put it into file number.txt
	int x = 19530; 
	w("x = ", x);
	writeF(x);
	// creating child process
	pid_t pid = fork();
	
	for (int i = 1; i <=5; i++) {
		
		sleep(1);
		if (pid == 0) {
			child();
		}
		else 
		{
			cout<< "\nIteration: "<< i <<endl;
			w("\nIteration ", i);
			x = parent(x, pid);
		}
	}
	//remove("number.txt");
	return 0;	
}