// Mustafa Chowdhuury, ge3306
#include <iostream>
#include <string>

using namespace std;
/*=====================================
creating node
=================================*/
struct node
{
	string process;
	node *next;
	int memoryUnit;
	node(string input, node *nNode)
	{
		process = input;
		nNode = next;
	}
};

/*=======================================================
initializing memory set unit
the empty unit is stored with "Empty" string
========================================================*/
void setMemoryUnits(node *&head)
{
	cout << "\nInitializing 10 unit memory space"<<endl;
	node *temp;
	
	temp = head;

	int i;
	int count = 0;

	// crating 10 nodes and initializing it as "Empty"
	for (i = 0; i<9; i++)
	{
		node *createNextNode;
		createNextNode = new node("Empty", NULL);
		temp->next = createNextNode;
		temp = temp->next;
	}
}
/*=======================================================
this function print memory
=======================================================*/
void print(node *head)
{
	node *temp;
	temp = head;
	int count = 1;

	while (temp != NULL)
	{
		cout << " (" << count<<")" <<temp->process << " -->>";
		temp = temp ->next;
		count++;
	}
	//cout<<"\n---------------------------------------------------------------------------------------------------------\n"<<endl;
	cout<<"\n" <<endl;
}
/*=================================
This function distory all allocated memory upon end of the program
===================================*/
void distroyLinkedList(node *head)
{
	
	node *temp;

	temp = head;

	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
		
	}
	head = NULL;	
}

/*=================================================================
this function de-allocate memory, so this fuction looks how many
units a process took in the memory then its clear it up and 
set as "Empty"
==================================================================*/
void freeMemory(node *&head, string ProcessName, int unit)
{
	cout << "Process " <<ProcessName<< " is running\n";
	cout<<"------------------------"<<endl;
	int count = 0;
	node *temp = head;
	
	// getiing first node value
	string processNameFound = temp->process;
	node *current = temp;

	while (temp !=NULL && count != unit)
	{	
		// if the node already set as "Empty" then point to 
		// next node without incremention count
		if (temp->process == "Empty")
		{
			temp = temp->next;
			count = 0;
		}
		// if node value is match, increment count
		else if (temp->process == processNameFound)
		{
			temp = temp->next;
			count++;
		}
		// if the next node process is diffrent then the previous node process
		// then again set count to 0, and update the processNameFound with new process name
		else if (temp->process != processNameFound)
		{
			processNameFound = temp->process;
			count = 0;
		}
	}
	// traverse node current from where the process with same unit was found
	while (processNameFound != current->process)
	{
		current = current->next;
	}
	
	// de-allocating memory and set it as "Empty"
	for (int i = 0; i<unit; i++)
	{
	 	current->process = "Empty";
	 	current = current->next;
	}

}

/*=============================================================
this fuction allocate memory with continious unit, if there is a process in between
empty nodes and unit doesn't fit in the hole, 
it will start looking for the hole after located processes
===============================================================*/

void firstfit(node *head, string processName, int unit)
{

	cout << "Process " << processName<< " is running\n";
	cout<<"------------------------"<<endl;

	node *temp, *current, *temp1;
	temp = head;

	int count = 0;
	
	current = temp;
	// tereverse the linked list untill its null and count < unit
	while (temp != NULL && count < unit)
	{
		// if the nodes is "Empty", increment count and traverse
		if (temp->process == "Empty")
		{
			temp = temp->next;
			count++;
		}
		// if there is a node which is allocated by a process 
		// set count =0, and treverse linked lisst
		else if (temp->process != "Empty")
		{

			temp = temp->next;
			current = temp;
			count = 0;
		}
	}
	//cout<<"********* Count = "<<count<< " & unit="<<unit <<endl;
	// if we found enough memory unit to fit the process 
	if (count == unit)
	{
		// allocate memory with given process
		for (int i =0; i<unit; i++)
		{
			current->process = processName;
			current = current->next;
		}
	}
	// if there are not enough holes.
	else
	{
		cout<<"Process "<<processName<<" dont have free " << unit << " unit free memory space" <<endl;
	}
}


int main()
{
	node *head;
	head = new node("Empty", NULL);

	setMemoryUnits(head);
	print(head);
	
	
	firstfit(head, "A", 2);
	firstfit(head, "B", 3);
	firstfit(head, "C", 4);
	print(head);


	freeMemory(head, "D", 3);
	print(head);
	

	firstfit(head, "E", 1);
	print(head);
	

	freeMemory(head, "F", 4);
	print(head);
	
	freeMemory(head, "G", 2);
	print(head);

	firstfit(head, "I", 5);
	print(head);

	
	distroyLinkedList(head);

	return 0;
}