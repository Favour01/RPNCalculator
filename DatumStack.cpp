/***************************************
COMP 15 PROJ1
FAVOUR OKEREKE-MBA (fokere01)
DatumStack.cpp
10/12/2017
***************************************/
#include <iostream>
#include <string>
#include "DatumStack.h"

using namespace std;

/*********************
constructor
Initialises intSize to 0 and front to NULL 
*********************/
DatumStack::DatumStack(){
	front = NULL;
	intSize = 0;
}

/*********************
constructor
Takes in an array of datum and creates a stack of datum containing the same
elements as the array
*********************/
DatumStack::DatumStack(Datum ray[], int size){
	intSize = 0;
	front = NULL;
	for(int i = 0; i < size; i++)
		push(ray[i]);
}

/*********************
 Destructor
 Deletes all memory on the heap
*********************/
DatumStack::~DatumStack(){
	clear();
}

/*********************
 push
 creates a new DatumNode and adds it to the front of the list
*********************/
void DatumStack::push(Datum data){
	DatumNode *tempNode;
	tempNode = new DatumNode(data);
	tempNode->next = front;
	front = tempNode;
	tempNode = NULL;
	intSize++;
}

/*********************
 pop
 Removes the DatumNode at the front pf the list
*********************/
void DatumStack::pop(){
	if(isEmpty())
		throw runtime_error("empty_stack");
	else{
		DatumNode *tempNode;
		tempNode = front;
		front = front->next;
		delete tempNode;
		intSize--;
	}
}

/*********************
 clear
 MAkes the stack an empty stack
*********************/
void DatumStack::clear(){
	DatumNode *tempNode;
	for(tempNode = front; tempNode != NULL; tempNode = front)
		pop();
}

/*********************
 size
 Returns the size of the stack
*********************/
int DatumStack::size(){
	return intSize;
}

/*********************
 isEmpty
 Checks if the stack is Empty
*********************/
bool DatumStack::isEmpty(){
	return (front == NULL);
}

/*********************
 top
 Returns the datum that was last added to the stack
*********************/
Datum DatumStack::top(){
	if(isEmpty())
		throw runtime_error("empty_stack");
	else
		return front->datum;
}

/************************PRINT FUNCTIONS**********************/
void DatumStack::print_top(Datum data){
	string result = data.toString();
	cout << result << endl;
}

void DatumStack::print(){
	DatumNode *tempNode;
	tempNode = front;
	while (tempNode != NULL){
		Datum data = tempNode->datum;
		string result = data.toString();
		cout << result << endl;
		tempNode = tempNode->next;
	}
}