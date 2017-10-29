/***************************************
COMP 15 PROJ1
FAVOUR OKEREKE-MBA (fokere01)
DatumStack.h
10/12/2017
***************************************/
#ifndef DATUMSTACK_H_
#define DATUMSTACK_H_

#include "Datum.h"
#include <string>

using namespace std;

class DatumStack {
public:
	/***************************
		Function: Constructor
		Parameters: None
		Returns: Nothing
	******************************/
	DatumStack();

	/***************************
		Function: Constructor
		Parameters: A datum array and the size of the array
		Returns: Nothing
	******************************/
	DatumStack(Datum ray[], int size);

	/***************************
		Function: Destructor
		Parameters: None
		Returns: Nothing
	******************************/
	~DatumStack();

	/***************************
		Function: isEmpty
		Parameters: None
		Returns: A boolean
	******************************/
	bool isEmpty();

	/***************************
		Function: clear
		Parameters: None
		Returns: Nothing
	******************************/
	void clear();

	/***************************
		Function: size
		Parameters: None
		Returns: the size of the linked list
	******************************/
	int size();

	/***************************
		Function: top
		Parameters: None
		Returns: The datum that was last added to the stack
	******************************/
	Datum top();

	/***************************
		Function: pop
		Parameters: None
		Returns: Nothing
	******************************/
	void pop();

	/***************************
		Function: push
		Parameters: A datum to add to the stack
		Returns: Nothing
	******************************/
	void push(Datum data);


/************************************************************/
	void print_top(Datum data);
	void print();
/************************************************************/
private:
	struct DatumNode{
		Datum datum;
		DatumNode *next;
		DatumNode(int n): datum(n), next(NULL){}
		DatumNode(bool val): datum(val), next(NULL){}
		DatumNode(string comm): datum(comm), next(NULL){}
		DatumNode(Datum data): datum(data), next(NULL){}
	};
	//pointer to the front of the list
	DatumNode *front;

	//size of the list
	int intSize;
};

#endif