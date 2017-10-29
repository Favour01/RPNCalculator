/***************************************
COMP 15 PROJ1
FAVOUR OKEREKE-MBA (fokere01)
RPNCalc.cpp
10/12/2017
***************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "RPNCalc.h"

using namespace std;

/*********************
constructor
Sets track to true
*********************/
RPNCalc::RPNCalc(){
	//DatumStack stack;
	track = true;
}

/*************************
destructor
**************************/
RPNCalc::~RPNCalc(){

}

/**************************
run
kick starts the program
****************************/
void RPNCalc::run(){
	run_from(cin);
}

/****************************************
*run_from
*runs commands from the provided stream
******************************************/
void RPNCalc::run_from(istream &file){
	string command;
	int num;
	while ((track == true) && (file >> command)){
		if (got_int(command, &num))
			push_int(num);
		else if (command == "{"){
			evaluate_codeblock(file);
		}
		else if (command == "quit"){
			track = false;
			break;
		}
		else if (command == "file")
			evaluate_file(file);
		else
			decide_command(command);
	}
}

/*************************************
*decide_command
*runs the command determined by the string
*****************************************/
void RPNCalc::decide_command(string com){
	if ((com == "#t") || (com == "#f"))
		push_bool(com);
	else if (com == "drop")
		evaluate_drop();
	else if (com == "not")
		evaluate_not();
	else if (com == "print")
		evaluate_print();
	else if (com == "clear")
		evaluate_clear();
	else if (com == "dup")
		evaluate_dup();
	else if (com == "swap")
		evaluate_swap();
	else if (com == "if")
		evaluate_if();
	else if (com == "exec")
		evaluate_exec();
	else if(com == "+" || com == "-" || com == "*" ||
			 com == "/" || com == "mod")
		evaluate_arithmetic(com);
	else if(com == "<" || com == ">" || com == "<=" ||
			 com == ">=" || com == "==" || com == "!=")
		evaluate_compare(com);
	else
		cerr << com << ": unimplemented\n";
}

/*********************
push_int
adds the integer passed to the top of the stack
***********************/
void RPNCalc::push_int(int num){
	Datum add = Datum(num);
	stack.push(add);
}

/*********************
push_string
adds the string passed to the top of the stack
**********************/
void RPNCalc::push_string(string codeBlock){
	Datum add = Datum(codeBlock);
	stack.push(add);
}

/*********************
push_bool
adds the boolean passed to the top of the stack
***********************/
void RPNCalc::push_bool(string condition){
	bool checked = evaluate_bool(condition);
	Datum add = Datum(checked);
	stack.push(add);
}

/**************************
evaluate_bool
returns the required boolean
****************************/
bool RPNCalc::evaluate_bool(string condition){
	bool add;
	if (condition == "#t"){
		add = true;
	}
	else {
		add = false;	
	}
	return add;
}

/*******************************
evaluate_drop
removes top element on the stack
********************************/
void RPNCalc::evaluate_drop(){
	try{
		stack.pop();
	}catch(runtime_error){
		cerr << "empty_stack\n" << endl;
	}	
}

/********************************
*evaluate_not
*if the first element in the stack is the boolean,
 it converts it to its opposite
*********************************/
void RPNCalc::evaluate_not(){
	try{
		if(top_isBool()){
			Datum top = stack.top();
			evaluate_drop();
			bool convert = top.getBool();
			Datum final = Datum(!convert);
			stack.push(final);
		}
		else
			cerr << "Error: datum_not_bool\n" << endl;
	}catch(runtime_error){
		cerr << "Error: empty_stack\n";
	}	
}

/*************************************
*evaluate_print
*prints the element at the top of the stack
**************************************/
void RPNCalc::evaluate_print(){
	try{
		Datum top = stack.top();
		string print = top.toString();
		cout << print << endl;
	}catch(runtime_error){
		cerr << "Error: empty_stack\n";
	}
}

/**************************************
*evaluate_clear
*clears the stack(claculator)
***************************************/
void RPNCalc::evaluate_clear(){
	stack.clear();
}

/***************************************
*evaluate_dup
*duplicates the element at the top of the stack
****************************************/
void RPNCalc::evaluate_dup(){
	try{
		Datum top = stack.top();
		stack.push(top);
	}catch(runtime_error){
		cerr << "Error: empty_stack\n";
	}
}

/*************************************
*evaluate_swap
*swaps the top two elements on the stack
**************************************/
void RPNCalc::evaluate_swap(){
	Datum data1(0);
	Datum data2(0);
	if (get_required(data1, data2)){
		stack.push(data1);
		stack.push(data2);
	}
}

/*************************************
*evaluate_codeblock
*pushes a codeblock onto the stack
**************************************/
void RPNCalc::evaluate_codeblock(istream &file){
	string codeblock;
	codeblock = parseCodeBlock(file);
	push_string(codeblock);
}

/***************************************
*evaluate_add
*adds the top two elements on the stack
****************************************/
void RPNCalc::evaluate_add(){
	Datum data1(0);
	Datum data2(0);
	if (get_required(data1, data2)){
		if (required_isInt(data1, data2)){
			int sum = (data2.getInt()) + (data1.getInt());
			push_int(sum);
		}
		else{
			cerr << "Error: datum_not_int\n";
		}
	}
}

/***************************************
*evaluate_subtract
*adds the top two elements on the stack
****************************************/
void RPNCalc::evaluate_subtract(){
	Datum data1(0);
	Datum data2(0);
	if (get_required(data1, data2)){
		if (required_isInt(data1, data2)){
			int sum = (data2.getInt()) - (data1.getInt());
			push_int(sum);
		}
		else{
			cerr << "Error: datum_not_int\n";
		}
	}
}

/***************************************
*evaluate_multiply
*adds the top two elements on the stack
****************************************/
void RPNCalc::evaluate_multiply(){
	Datum data1(0);
	Datum data2(0);
	if (get_required(data1, data2)){
		if (required_isInt(data1, data2)){
			int sum = (data2.getInt()) * (data1.getInt());
			push_int(sum);
		}
		else{
			cerr << "Error: datum_not_int\n";
		}
	}
}

/***************************************
*evaluate_division
*adds the top two elements on the stack
****************************************/
void RPNCalc::evaluate_division(){
	Datum data1(0);
	Datum data2(0);
	if (get_required(data1, data2)){
		if (required_isInt(data1, data2)){
			if (data1.getInt() == 0){
				cerr << "Error: division by 0\n";
				stack.push(data2);
				stack.push(data1);
			}
			else{
				int sum = (data2.getInt()) / (data1.getInt());
				push_int(sum);
			}
		}
		else{
			cerr << "Error: datum_not_int\n";
		}
	}	
}

/***************************************
*evaluate_modulo
*adds the top two elements on the stack
****************************************/
void RPNCalc::evaluate_modulo(){
	Datum data1(0);
	Datum data2(0);
	if (get_required(data1, data2)){
		if (required_isInt(data1, data2)){
			int sum = (data2.getInt()) % (data1.getInt());
			push_int(sum);
		}
		else{
			cerr << "Error: datum_not_int\n";
		}
	}
}

/**************************************
*evaluate_less
*compares two elements on the stack
***************************************/
void RPNCalc::evaluate_less(){
	Datum data1(0);
	Datum data2(0);
	try{
		if (get_required(data1, data2)){
			bool ans = data2 < data1;
			Datum final = Datum(ans);
			stack.push(final);
		}
	}catch(runtime_error){
		cerr << "Error: datum_not_int\n";
	}	
}

/**************************************
*evaluate_great
*compares two elements on the stack
***************************************/
void RPNCalc::evaluate_great(){
	Datum data1(0);
	Datum data2(0);
	try{
		if (get_required(data1, data2)){
			bool ans;
			if(data2 < data1)
				ans = false;
			else
				ans = true;
			Datum final = Datum(ans);
			stack.push(final);
		}
	}catch(runtime_error){
		cerr << "Error: datum_not_int\n";
	}	
}

/**************************************
*evaluate_equal
*compares two elements on the stack
***************************************/
void RPNCalc::evaluate_equal(){
	Datum data1(0);
	Datum data2(0);
		if (get_required(data1, data2)){
			bool ans = data2 == data1;
			Datum final = Datum(ans);
			stack.push(final);
		}
}

/**************************************
*evaluate_orless
*compares two elements on the stack
***************************************/
void RPNCalc::evaluate_orless(){
	Datum data1(0);
	Datum data2(0);
	try{
		if (get_required(data1, data2)){
			bool ans;
			if ((data2 < data1) || (data2 == data1))
				ans = true;
			else
				ans = false;
			Datum final = Datum(ans);
			stack.push(final);
		}
	}catch(runtime_error){
		cerr << "Error: datum_not_int\n";
	}	
}

/**************************************
*evaluate_orgreat
*compares two elements on the stack
***************************************/
void RPNCalc::evaluate_orgreat(){
	Datum data1(0);
	Datum data2(0);
	try{
		if (get_required(data1, data2)){
			bool ans;
			if ((!(data2 < data1)) || (data2 == data1))
				ans = true;
			else
				ans = false;
			Datum final = Datum(ans);
			stack.push(final);
		}
	}catch(runtime_error){
		cerr << "Error: datum_not_int\n";
	}	
}

/**********************************************
*evaluate_arithmetic
*decides with arithmetic command to carry out
**********************************************/
void RPNCalc::evaluate_arithmetic(string command){
	if (command == "+")
		evaluate_add();
	else if (command == "-")
		evaluate_subtract();
	else if (command == "*")
		evaluate_multiply();
	else if (command == "/")
		evaluate_division();
	else
		evaluate_modulo();
}

/**********************************************
*evaluate_compare
*decides with compare command to carry out
**********************************************/
void RPNCalc::evaluate_compare(string command){
	if (command == "<")
		evaluate_less();
	else if (command == ">")
		evaluate_great();
	else if (command == "<=")
		evaluate_orless();
	else if (command == ">=")
		evaluate_orgreat();
	else if (command == "==")
		evaluate_equal();
	else{
		evaluate_equal();
		evaluate_not();
	}
}

/*********************************************
*evaluate_file
*reads from a file
**********************************************/
void RPNCalc::evaluate_file(istream &file){
	string filename;
	file >> filename;
	ifstream input;
	input.open(filename.c_str());
	if (!input.is_open())
	{
		cerr << "Unable to read " << filename << endl;
	}
	else{
		run_from(input);
		input.close();
	}	
}

/********************************************
*evaluate_exec
*runs a code block
*********************************************/
void RPNCalc::evaluate_exec(){
	Datum codeblock = Datum(0);
	if (get_required(codeblock)){
		if (codeblock.isCodeBlock()){
			string execute = codeblock.getCodeBlock();
			istringstream file (execute);
			run_from(file);
		}
		else
			cerr << "Error: datum_not_codeBlock\n";
	}
}

/*******************************************
*evaluate_if
*similar to an if statement
*******************************************/
void RPNCalc::evaluate_if(){
	Datum falseCase = Datum(0);
	Datum trueCase = Datum(0);
	Datum condition = Datum(0);
	if (get_required(falseCase, trueCase)){
		if (falseCase.isCodeBlock() && trueCase.isCodeBlock()){
			if(get_required(condition)){
				if(condition.isBool()){
					if_helper(falseCase, trueCase, condition);
				}
				else{
					cerr << "Error: expected boolean in if test\n";
					stack.push(condition);
					stack.push(trueCase);
					stack.push(falseCase);
				}
			}
			else{
				stack.push(trueCase);
				stack.push(falseCase);
			}
		}
		else{
			cerr << "Error: expected codeblock in if branch\n";
			stack.push(trueCase);
			stack.push(falseCase);
		}
	}
}

/******************************************
*if_helper
*helps the evaluate_if funtion
*******************************************/
void RPNCalc::if_helper(Datum falseCase, Datum trueCase, Datum condition){
	bool decide = condition.getBool();
	if (decide){
		stack.push(trueCase);
		evaluate_exec();
	}
	else{
		stack.push(falseCase);
		evaluate_exec();
	}
}

/****************************************
*parseCodeBlock
*takes in a codeblock and return it as a string 
******************************************/
string RPNCalc::parseCodeBlock(istream &input){
	string addon, codeBlock = "";
	int balanced = 0;
	while(input >> addon){
		if (addon == "{"){
			balanced++;
			codeBlock = codeBlock + addon + " ";
		}
		else if((addon == "}") && (balanced > 0)){
			balanced--;
			codeBlock = codeBlock + addon + " ";
		}
		else if((addon == "}") && (balanced == 0)){
			return codeBlock;
		}
		else
			codeBlock = codeBlock + addon + " ";
	}
	return codeBlock;
}

/**********************************
*get_required
*gets the required number of elements from the stack
************************************/
bool RPNCalc::get_required(Datum &data1, Datum &data2){
	int count = 0;
	try{
		for(int i = 0; i < 2; i++){
			Datum top = stack.top();
			if (i == 0)
				data1 = top;
			else
				data2 = top;
			evaluate_drop();
			count++;
		}
		return true;
	}catch(runtime_error){
		cerr << "Error: empty_stack\n";
		if (count == 1)
			stack.push(data1);
		return false;
	}
}

/**********************************
*get_required
*gets the required number of elements from the stack
************************************/
bool RPNCalc::get_required(Datum &data1){
	try{
		Datum top = stack.top();
		data1 = top;
		evaluate_drop();
		return true;
	}catch(runtime_error){
		cerr << "Error: empty_stack\n";
		return false;
	}
}

/**********************************
*required_isInt
*checks if both tops are ints
***********************************/
bool RPNCalc::required_isInt(Datum data1, Datum data2){
	if ((data1.isInt()) && (data2.isInt()))
		return true;
	else{
		stack.push(data2);
		stack.push(data1);
		return false;
	}
}

/**********************************
got_int
Writen by MARK SHELDON
Return true if the string s can be interpreted as an integer number
and places the associated integer into the location pointed to by
resultp.
***********************************/
bool RPNCalc::got_int(string s, int *resultp)
{
        return sscanf(s.c_str(), "%d", resultp) == 1;
}


/*************************************
top_isBool
checks if the top element on the stack is a boolean
**************************************/
bool RPNCalc::top_isBool(){
	Datum check = stack.top();
	return check.isBool();
}