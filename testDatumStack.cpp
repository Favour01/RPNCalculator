/***************************************
COMP 15 PROJ1
FAVOUR OKEREKE-MBA (fokere01)
testDatumStack.cpp
10/12/2017
***************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "DatumStack.h"

using namespace std;

void testarray_cons();
void test_top(DatumStack &stack);
void test_pop(DatumStack &stack);

int main()
{
	DatumStack stack;

	cout << "*****TESTING SIZE*****" << endl;
	int size = stack.size();
	cout << "The current size of your stack is: " << size << endl;

	cout << "Testing push. Size should increase by 1" << endl;
	Datum add(16);
	stack.push(add);
	size = stack.size();
	cout << "Expected result: 1" << endl;
	cout << "The current size of your stack is: " << size << endl << endl;


	testarray_cons();
	return 0;
}

void testarray_cons(){
	cout << "*****TESTING ARRAY CONSTRUCTOR & isEMPTY*****" << endl;

	Datum array[3] = {Datum(4), Datum(string("{ 2 3 + { #t } }")), Datum(true)};
	DatumStack stack(array, 3);

	int size = stack.size();
	cout << "The current size of your stack is: " << size << endl;
	cout << "Expected result: false" << endl;

	bool ans = stack.isEmpty();
	if (ans == true)
		cout << "Actual result: true" << endl << endl;
	else
		cout << "Actual result: false" << endl << endl;

	test_top(stack);
}

void test_top(DatumStack &stack){
	cout << "*****TESTING TOP & PUSH*****" << endl;
	Datum add = Datum(string("2 3 + { #t } if"));
	//Datum add = Datum(16);
	//Datum add = Datum(string("#t"));
	stack.push(add);
	int size = stack.size();
	cout << "Expected result of size: 4" << endl;
	cout << "The current size of your stack after push is: " << size << endl;
	cout << "Expected result: { 2 3 + { #t } if }" << endl;
	Datum top = stack.top();
	string result = top.toString();
	cout << "The top is: " << result << endl << endl;
	test_pop(stack);
	cout << "*****TESTING CLEAR*****" << endl;
	stack.clear();
	size = stack.size();
	cout << "Expected result: 0" << endl;
	cout << "The current size of your stack after clear is: " << size << endl 
		 << endl;
}

void test_pop(DatumStack &stack){
	cout << "*****TESTING POP*****" << endl;
	stack.pop();
	int size = stack.size();
	cout << "Expected result: 3" << endl;
	cout << "The current size of your stack after pop is: " << size << endl;
	cout << "Expected result: true" << endl;
	Datum top = stack.top();
	if (top.isInt()){
		int result = top.getInt();
		cout << "The top is: " << result << endl;
	}
	else if(top.isBool()){
		bool result = top.getBool();
		if (result == true)
			cout << "The top is: true" << endl << endl;
		else
			cout << "The top is: false" << endl << endl;
	}
	else{
		string result = top.getCodeBlock();
		cout << "The top is: " << result << endl << endl;
	}
}