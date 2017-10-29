/***************************************
COMP 15 PROJ1
FAVOUR OKEREKE-MBA (fokere01)
RPNCalc.h
10/12/2017
***************************************/
#ifndef RPNCALC_H_
#define RPNCALC_H_

#include "DatumStack.h"
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

class RPNCalc {
public:
	/***************************
		Function: Constructor
		Parameters: None
		Returns: Nothing
	******************************/
	RPNCalc();

	/******************************
		Function: Destructor
		Parameters: None
		Returns: Nothing
	*******************************/
	~RPNCalc();

	/*******************************
		Funtion: run
		Parameters: None
		Returns: Nothing
	*********************************/
	void run();

private:
	DatumStack stack;
	bool track;

	/***************************
		Function:push_int
		Paremeters: integer to be added 
					to the top of the stack
		Returns: Nothing
	******************************/
	void push_int(int num);

	/*************************
		Function:push_string
		Parameters: string to be added 
					to the top of the stack
		Returns: Nothing
	**************************/
	void push_string(string codeBlock);


	/*************************
		Function:push_bool
		Parameters: boolean to be added 
					to the top of the stack
		Returns: Nothing
	**************************/
	void push_bool(string condition);


	/*************************
		Function: evaluate_bool
		Paramaeters: string to be evaulated 
					 to determine true/false
		Returns: Desired boolean
	**************************/
	bool evaluate_bool(string condition);

	/**************************
		Function: evaluate_drop
		Parameters: None
		Returns: Nothing
	****************************/
	void evaluate_drop();

	/***************************
		Function: evaluate_not
		Parameters: None
		Returns: Nothing
	****************************/
	void evaluate_not();

	/****************************
		Function: evaluate_print
		Parameters: None
		Returns: Nothing
	*****************************/
	void evaluate_print();

	/****************************
		Function: evaluate_clear
		Parameters: None
		Returns: Nothing
	****************************/
	void evaluate_clear();

	/****************************
		Function: evaluate_dup
		Parameters: None
		Returns: Nothing
	*****************************/
	void evaluate_dup();

	/*****************************
		Funtion: evaluate_swap
		Parameters: None
		Return: Nothing
	*****************************/
	void evaluate_swap();

	/****************************
		Function: evaluate_add
		Parameters: None
		Return: Nothing
	****************************/
	void evaluate_add();

	/****************************
		Function: evaluate_subtract
		Parameters: None
		Return: Nothing
	****************************/
	void evaluate_subtract();

	/****************************
		Function: evaluate_multiply
		Parameters: None
		Return: Nothing
	****************************/
	void evaluate_multiply();

	/****************************
		Function: evaluate_division
		Parameters: None
		Return: Nothing
	****************************/
	void evaluate_division();

	/****************************
		Function: evaluate_modulo
		Parameters: None
		Return: Nothing
	****************************/
	void evaluate_modulo();

	/****************************
		Function: evaluate_less
		Parameters: None
		Return: Nothing
	****************************/
	void evaluate_less();

	/****************************
		Function: evaluate_great
		Parameters: None
		Return: Nothing
	****************************/
	void evaluate_great();

	/****************************
		Function: evaluate_equal
		Parameters: None
		Return: Nothing
	****************************/
	void evaluate_equal();

	/****************************
		Function: evaluate_orless
		Parameters: None
		Return: Nothing
	****************************/
	void evaluate_orless();

	/****************************
		Function: evaluate_orgreat
		Parameters: None
		Return: Nothing
	****************************/
	void evaluate_orgreat();

	/*****************************
		Funtion: evaluate_arithmatic
		Parameters: string with the desired command
		Returns: Noting
	******************************/
	void evaluate_arithmetic(string command);

	/*****************************
		Funtion: evaluate_compare
		Parameters: string with the desired command
		Returns: Noting
	******************************/
	void evaluate_compare(string command);

	/*******************************
		Funtion: run_from
		Parameters: istream to read from
		Returns: Nothing
	*********************************/
	void run_from(istream &file);

	/*******************************
		Funtion: decide_command
		Parameters: string that determines the command
		Returns: Nothing
	*********************************/
	void decide_command(string com);

	/********************************
		Function : parseCodeBlock
		Parameters: 
		Returns: Nothing
	*********************************/
	string parseCodeBlock(istream &input);

	/*****************************
		Funtion: evaluate_codeblock
		Parameters: istream to read from
		Returns: Noting
	******************************/
	void evaluate_codeblock(istream &file);

	/*****************************
		Function: evaluate_file
		Parameters: istream to read from
		Returns: Noting
	******************************/
	void evaluate_file(istream &file);

	/*****************************
		Function: evaluate_exec
		Parameters: None
		Returns: Noting
	******************************/
	void evaluate_exec();

	/*****************************
		Function: evaluate_if
		Parameters: None
		Returns: Noting
	******************************/
	void evaluate_if();

	/******************************
		Function: if_helper
		Parameters: falseCase, trueCase, condition
		Return: Nothing
	*******************************/
	void if_helper(Datum falseCase, Datum trueCase, Datum condition);

	/*****************************
		Funtion: get_required
		Parameters: Datums passed by reference
		Returns: A boolean confirming they were gotten
	*****************************/
	bool get_required(Datum &data1, Datum &data2);

	/*****************************
		Funtion: get_required
		Parameters: Datum passed by reference
		Returns: A boolean confirming they were gotten
	*****************************/
	bool get_required(Datum &data1);

	/****************************
		Function: required_isInt
		Parameters: Datums passed by reference
		Returns: A boolean confirming 
	*****************************/
	bool required_isInt(Datum data1, Datum data2);

	/**************************
		Function: got_int
		Parameters: a string and an int 
		Returns: a boolean
	***************************/
	bool got_int(string s, int *resultp);

	/****************************
		Function: top_isBool
		Parameters: None
		Returns: a boolean
	*****************************/
	bool top_isBool();

	/**************DELETETHIS********************/
	void test_print();
	/*********************************************/
};

#endif