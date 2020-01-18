/*
	ENGR2400 Data Structures and Algorithms
	Fall 2019
	Ryley Danielson
	Programming Assignment 2 - List ADT with a Linked  List
	The goal of this assignment is to create a List abstract data type class using a linked-list as the base for the list implementation.
	The number of steps a method takes to complete is based on actions specifically involving the List where variable memory is accessed, a calculation is done, a comparison is done, or a value is returned
*/

//Includes libraries needed for the program
#include<iostream>
#include<iomanip>
#include <fstream>

//This program uses the standard namespace
using namespace std;

//Class used as a template to build new nodes
class node 
{
public:
	int data;
	node* next;
};


//Global Variables used by the program
int allSteps = 0; //Counter for total number of steps the program performs on the list
int sizeList = 0; //Tracks the size of the list
int i = 0; //Integer fields used in class methods
int o = 0; //Integer fields used in class methods
int choice; //Varable storing user menue input
node* head; // Head pointer of the linked list
ofstream myfile; //File stream for program 

/*
Creates a new node for te liked list 
The data value is set equal to equal to int o which is detemined by user input
The pointer value of the next not is automatically set to NULL
This method returns the pointer value for the new node
*/
node * createNode(int o) 
{
	node* newNode = new node;
	newNode->data = o;
	newNode->next = NULL;
	return newNode;
}

/*
	Checks to see if the List is empty by checking a counter sizeList
	Returns 1 if empty (sizeList <= 0)
	Returns 0 if not empty
*/
int isEmpty()
{

	int localSteps = 3;
	allSteps = allSteps + localSteps;

	if (sizeList >= 0)
	{
		//Confirmation message
		cout << "The list is not empty. Return 0\n";
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The list is not empty. Return 0\n";
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return 0;
	}
	else
	{
		//Confirmation message
		cout << "The list is empty. Return 1\n";
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The list is empty. Return 1\n";
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return 1;
	}
}

/*
	Checks the size of the list using the counter variable sizeList
	Returns the integer size value stored in sizeList
*/
int size()
{
	int localSteps = 2;
	allSteps = allSteps + localSteps;

	//Confirmation message 
	cout << "The size of the list is " << sizeList << endl;
	cout << "Number of steps taken to complete action " << localSteps << endl;
	myfile << "The size of the list is " << sizeList << endl;
	myfile << "Number of steps taken to complete action " << localSteps << endl;

	return sizeList;
}


/*
	Returns the integer value at the user inputted index (i)
*/
int get(int i)
{
	int localSteps = 15;
	node *tempNode = head;

	//Checks the index to make sure it is a location currently supported by the array and return an error message if this check fails
	if ((i >= 0) && (i <= (sizeList - 1)) && (head != NULL))
	{

		node *tempNode = head;// temporary node poiter set equal to the head pointer
		int loc = 0; //iterator definng the current location in the array

		//Loop that iterates trough an array until it reaches the index i
		while (loc != i)
		{
			tempNode = tempNode->next;
			loc++;

			localSteps += 3;
		}
		
		
		allSteps += localSteps;
		
		//Confirmation message 
		cout << "The element at index " << i << " is " << tempNode->data << endl;
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The element at index " << i << " is " << tempNode->data << endl;
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return tempNode->data;

	}

	localSteps = 13;
	allSteps += localSteps;

	//Error message
	cout << "Cannot complete action. Input not valid, or index is not being used. Return value -1\n";
	cout << "Number of steps taken to complete action " << localSteps << endl;
	myfile << "Cannot complete action. Input not valid, or index is not being used. Return value -1\n";
	myfile << "Number of steps taken to complete action " << localSteps << endl;
	return -1;
}


/*
	Sets and integer value of a particular index. Index and value are determined by the user input
	Returns the replaced value when successful
*/
int set(int i, int o)
{
	//Checks the index to make sure it is a location currently supported by the array, reutrns -1 and an error message if i does not meet this check
	if ((i >= 0) && (i <= (sizeList - 1)) && (head!=NULL))
	{
		int localSteps = 15;

		node *tempNode = head;
		int loc = 0; 
		while (loc != i)//Finds node at index i
		{
			tempNode = tempNode->next;
			loc++;

			localSteps += 3;
		}
		int tempNodeData = tempNode->data;//Stores old value of node data
		tempNode->data = o; //Sets data of node at index i

		allSteps += localSteps;

		//Confirmation message
		cout << "The element is now " << o << " at index " << i << " the value replaced was " << tempNodeData << endl;
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The element is now " << o << " at index " << i << " the value replaced was " << tempNodeData << endl;
		myfile << "Number of steps taken to complete action " << localSteps << endl;

		return tempNodeData;
	}
	else
	{
		int localSteps = 11;
		allSteps +=  localSteps;

		//Error message
		cout << "Cannot complete action. Input not valid or elements must first be added.\n" << "Only indexes lest than " << sizeList << " can be set. Return value -1.\n";
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "Cannot complete action. Input not valid or elements must first be added.\n" << "Only indexes lest than " << sizeList << " can be set. Return value -1.\n";
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return -1;
	}

}

/*
	Adds a value to the list at an index. Both the index and input values are determined by the user
	Value is added to the end of the linked list, at the head pointer (both when head is NULL and is not NULL), and in the middle at index i.
	Increases the size of the list (sizeList)
	Returns the new list size when successful
*/
int add(int i, int o)
{
	int localSteps = 0;

	//Checks the index to make sure it is a location currently supported by the array, prints error message if the check fails
	if ((i < 0)  || (i > sizeList)) {

		localSteps += 6;
		allSteps += localSteps;

		cout << "Cannot complete action. Input not valid, or index entered is greater than next availible index, " << sizeList << ".\n More elemebts must be added. Return value -1\n";
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "Cannot complete action. Input not valid, next availible index for addition is " << sizeList << ".\n More elemebts must be added to use this index. Return value -1\n";
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return -1;
	}
	//Sets the head pointer if the head node is Null at index 0
	else if (i == 0 && head == NULL)
	{
		localSteps += 21;
		allSteps += localSteps;

		head = createNode(o); //Sets head equal to a new node with data o

		sizeList++;
		cout << "The new size of the list is " << sizeList << endl;
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The new size of the list is " << sizeList << endl;
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return sizeList;
	}
	//Sets the head pointer if the head node is Null at index 0
	else if (i == 0 && head != NULL)
	{
		node* tempNodeI = head; //temp pointer is set equal to the head pointer
		node* tempNodeII = createNode(o); //temp 2 is set equal to a new node
		node* tempNodeIII = head->next; //temp 3 is set equal to the pointer to the node after the head
		head = tempNodeII; //the head pointer is set equal to the new node pointer
		tempNodeII->next = tempNodeI; //the new pointer is set to point to the orgiginal node pointer that came after the head

		localSteps += 32;
		allSteps += localSteps;

		sizeList++;
		cout << "The new size of the list is " << sizeList << endl;
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The new size of the list is " << sizeList << endl;
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return sizeList;
	}
	else
	{
		localSteps += 24;

		node *tempNodeI = head; //temp pointer is set equal to the head pointer
		node *tempNodeII = createNode(o); //temp 2 is set equal to a new node
		node* tempNodeIII;
		int loc = 0;
		while (loc != (i-1)) //finds node at index i-1
		{
			tempNodeI = tempNodeI->next;
			loc++;
			
			localSteps += 3;
		}
		
		//Performs if the element is at the end of the linked list
		if (loc == sizeList) 
		{
			tempNodeI->next = tempNodeII; //Current node at the location set to point at new node
			localSteps += 8;
		}
		//Performs if the element is anywhere in the middle of the list
		else
		{
			
			tempNodeIII = tempNodeI->next; //temp node 3 set qual to node after the current node
			tempNodeI->next = tempNodeII; //Current node set to point toward the new node as the next nde
			tempNodeII->next = tempNodeIII; //New node set to point to the original node after the current node
			localSteps += 9;
		}

		allSteps += localSteps;

		sizeList++;
		cout << "The new size of the list is " << sizeList << endl;
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The new size of the list is " << sizeList << endl;
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return sizeList;
	}
	
}

/*
	Removes a value in the list at an index. Both the index and input values are determined by the user
	Value is removed at the end of the list or removes item from the indexed location and moves every item down one to the left from the idexed location.
	Increases the size of the list (sizeList)
	Returns the removed value when successful
*/
int remove(int i)
{
	int localSteps = 0;
	int tempInt = 0;

	//Checks the index to make sure it is a location currently supported by the array and return an error if any of the conditions below are met
	if ((sizeList == 0) || (i < 0) || (i > sizeList) || head == NULL)
	{
		localSteps = 11;
		allSteps += localSteps;

		cout << "Can not complete action. Input not valid. Return value -1\n";
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "Can not complete action. Input not valid. Return value -1\n";
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return -1;
	}
	else if (i == 0)
	{
		localSteps = 26;
		
		node* tempNodeI = head; //temp node set equal to head
		node* tempNodeII = head->next; //temp node 2 set equal to node after head
		
		//Performs if the pointer to the node after the head is Null
		if (head->next == NULL)
		{
			tempInt = tempNodeI->data; //stores the data at head node
			head = NULL; //set head node equal to null

			localSteps += 5;
			allSteps += localSteps;
		}
		else
		{
			node* tempNodeIII = tempNodeII->next;// temp node 3 equals the node after temp 2
			tempInt = tempNodeI->data; //stores the data value at the head node
			head = tempNodeII; //as the head point toward the node after the removed node
			
			localSteps += 8;
			allSteps += localSteps;
		}
		

		sizeList--;
		cout << "The element you removed is " << tempInt << " at index " << i << " The size of the list is now " << sizeList << endl;
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The element you removed is " << tempInt << " at index " << i << " The size of the list is now " << sizeList << endl;
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return  tempInt;
	}
	//Performs if the node to be removed is at the end of the linked list
	else if (i == (sizeList-1)) 
	{
		
		localSteps += 16;

		node* tempNodeI = head;
		node* tempNodeII;
		int loc = 0;
		while (loc != (i - 1))// Finds node at index i-1
		{
			tempNodeI = tempNodeI->next;
			loc++;
			
			localSteps += 3;
		}

		tempNodeII = tempNodeI->next; //temp node 2 set equal to the last node
		tempInt = tempNodeII->data; //stores the data at the last not
		tempNodeI->next = NULL; //has the seond to last node pont to null, now becoming the last node

		allSteps += localSteps;
		
		sizeList--;
		cout << "The element you removed is " << tempInt << " at index " << i << " The size of the list is now " << sizeList << endl;
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The element you removed is " << tempInt << " at index " << i << " The size of the list is now " << sizeList << endl;
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return  tempInt;
	}
	//Performes if removing from the middle
	else
	{
		localSteps +=22;

		node* tempNodeI = head;
		node* tempNodeII;
		node* tempNodeIII;
		

		int loc = 0;
		while (loc != (i - 1))// Finds the node at index i-1
		{
			tempNodeI = tempNodeI->next;
			loc++;
			
			localSteps += 3;
		}

		tempNodeII = tempNodeI->next;// sets temp2 equal to the the node after the current
		tempNodeIII = tempNodeII->next;// sets temp3 equal to the node after temp2
		int tempInt = tempNodeII->data;// stores the data in temp node 2
		tempNodeI->next = tempNodeIII;// points the curent node toward temp3

		allSteps += localSteps;

		sizeList--;
		cout << "The element you removed is " << tempInt << " at index " << i << " The size of the list is now " << sizeList << endl;
		cout << "Number of steps taken to complete action " << localSteps << endl;
		myfile << "The element you removed is " << tempInt << " at index " << i << " The size of the list is now " << sizeList << endl;
		myfile << "Number of steps taken to complete action " << localSteps << endl;
		return  tempInt;
	}
	
}


/*
	Runs the user interface which interacts with all ListADT methods.
	Outputs a text file of all program inputs and outputs when properly exitted
*/
int main()
{

	cout << "ENGR2400 Data Structures and Algorithms\nFall 2019\nRyley Danielson\nProgramming Assignment 2 - List ADT\nThe goal of this assignment is to create a List abstract data type class using a linked-list as the base for the list implementation.\nThe number of steps a method takes to complete is based on actions specifically involving the List where variable memory is accessed, a calculation is done, a comparison is done, or a value is returned \n\n";
	myfile << "ENGR2400 Data Structures and Algorithms\nFall 2019\nRyley Danielson\nProgramming Assignment 2 - List ADT\nThe goal of this assignment is to create a List abstract data type class using a linked-list as the base for the list implementation.\nThe number of steps a method takes to complete is based on actions specifically involving the List where variable memory is accessed, a calculation is done, a comparison is done, or a value is returned \n\n";

	myfile.open("OutputLog.txt");//Open file steam for program

	bool exit = false; //Begining exit value

	cout << "Choose an action by pressing the number for the action (1,2,3...):\n(1)Check if List is Empty\n(2)Check List Size\n(3)Get an Element from the List\n(4)Set and ELement in the List\n(5)Add and Element to the List\n(6)Remove an Element from the List\n(7)Exit the Program\n\n";
	myfile << "Choose an action by pressing the number for the action (1,2,3...):\n(1)Create Node\n(2)Check if List is Empty\n(3)Check List Size\n(4)Get an Element from the List\n(5)Set and ELement in the List\n(6)Add and Element to the List\n(7)Remove an Element from the List\n(8)Exit the Program\n\n";

	//User interface loop. Exits loop when the exit value is true (Option 7)
	do
	{
		
		cin >> choice;
		myfile << "Choice" << choice << endl;

		switch (choice)
		{
		case 1:
			isEmpty();
			break;
		case 2:
			size();
			break;
		case 3:
			cout << "Get which index in the list? (0,1,2,3...)\n";
			myfile << "Get which index in the list? (0,1,2,3...)\n";
			cin >> i;
			myfile << i << endl;

			get(i);
			
			break;
		case 4:
			cout << "Set which index in the list? (0,1,2,3...)\n";
			myfile << "Set which index in the list? (0,1,2,3...)\n";
			cin >> i;
			myfile << i << endl;
			cout << "Value for this index in the list? (0,1,2,3...)\n";
			myfile << "Value for this index in the list? (0,1,2,3...)\n";
			cin >> o;
			myfile << o << endl;
			set(i, o);
	
			break;
		case 5:
			cout << "Add at which index in the list? (0,1,2,3...)\n";
			myfile << "Add at which index in the list? (0,1,2,3...)\n";
			cin >> i;
			myfile << i << endl;
			cout << "Value for this index in the list? (0,1,2,3...)\n";
			myfile << "Value for this index in the list? (0,1,2,3...)\n";
			cin >> o;
			myfile << o << endl;
			add(i, o);

			break;
		case 6:
			cout << "Remove at which index in the list? (0,1,2,3...)\n";
			myfile << "Remove at which index in the list? (0,1,2,3...)\n";
			cin >> i;
			myfile << i << endl;
			remove(i);
			
			break;
		case 7:
			exit = true;

			cout << "Exiting program: " << exit << endl;
			myfile << "Exiting program: " << exit << endl;

			break;
		default:
			cout << "\nYou have input an improper selection, please choose again\n";
			myfile << "\nYou have input an improper selection, please choose again\n";

			break;
		}
			//Outputs the current List to the console
			if (head != NULL) 
			{
				cout << "Current List: ";
				myfile << "Current List: ";
				//cout << head->data << ", "<< endl;
				node* tempNode = head;
				
				while (tempNode != NULL)
				{
					cout << tempNode->data << ", ";
					myfile << tempNode->data << ", ";
					tempNode = tempNode->next;
				}
				cout << endl;
				myfile << endl;
			}
	} while (exit == false);

		cout << "The total amout of steps taken during this session was: " << allSteps << endl;
		myfile << "The total amout of steps taken during this session was: " << allSteps << endl; //Outputs total number of steps taken in this session
		myfile.close(); //Close file stream

		return 0;
}