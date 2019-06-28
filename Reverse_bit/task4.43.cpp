#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
	ifstream read;

	vector<string>storeStr;

	string str;

	// reading from the file
	cout<< "Read File: "<<endl;
	read.open("textfile.txt");
	if (read.fail())
	{
		cout<<"Error to read the file"<<endl;
		return -1;
	}
	while (read.good() && !read.eof())
	{
		getline(read, str);
		cout<<str<<endl;

		// push back whole line into vector
		storeStr.push_back(str);
		if (read.eof())
			break;
	}
	read.close();

	// store line into a new vector from bottom to top
	vector<string>reverse;
	for (int i =storeStr.size() ; i>=0; i--)
	{
		reverse.push_back(storeStr[i]);
	}
	
	char C[100];
	//string s = reverse.at(1);
	string s;

	cout<< "\nReversing each byte: ";
	for (int j=0; j<reverse.size();j++)
	{
		s = reverse[j];
		
		// create c string from string
		strcpy(C, s.c_str());
		// get the length of the screen
		int len = strlen(C);
		//reverse(C, n);

		// using stl library to store c string
		stack<char>S;
		//char empty = '';

		// push to stack
		for (int i =0; i<len; i++)
			//if (C[i] != '\0')
			S.push(C[i]);

		// get the top value from stack then pop it
		for (int i =0; i<len; i++)
		{
			C[i] = S.top();
			S.pop();
		}

		// print and write the reverse order
		for (int i=0; i<len; i++)
		{
			cout<<C[i];

			ofstream write("output.txt",ios::app);
  			write<<C[i];
  			write.close();
		}

		cout<<endl;
		ofstream write("output.txt",ios::app);
  		write<<"\n";
  		write.close();
	}
	return 0;
}