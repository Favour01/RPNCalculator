/***************************************
COMP 15 PROJ1
FAVOUR OKEREKE-MBA (fokere01)
testRPNCalc.cpp
10/12/2017
***************************************/
#include <iostream>
#include <string>
#include "RPNCalc.h"

using namespace std;

void test_pushint();
void test_pushstring();
void test_pushbool();
void test_evaluatedrop();
void test_evaluatenot();
void test_evaluateprint();
void test_evaluateclear();
void test_evaluatedup();
void test_evaluateswap();
void test_getrequired();
void test_requiredisInt();
void test_evaluateadd();
void test_evaluatesubtract();
void test_evaluatemultiply();
void test_evaluatedivision();
void test_evaluatemodulo();
void test_evaluateless();
void test_evaluategreat();
void test_evaluateequal();
void test_evaluateorless();
void test_evaluateorgreat();
void test_evaluatearithmetic();
void test_evaluatecompare();
void test_run();


int main()
{
	test_run();
	test_pushint();
	test_pushstring();
	test_pushbool();
	test_evaluatedrop();
	test_evaluatenot();
	test_evaluateprint();
	test_evaluateclear();
	test_evaluatedup();
	test_evaluateswap();
	test_getrequired();
	test_requiredisInt();
	test_evaluateadd();
	test_evaluatesubtract();
	test_evaluatemultiply();
	test_evaluatedivision();
	test_evaluatemodulo();
	test_evaluateless();
	test_evaluategreat();
	test_evaluateequal();
	test_evaluateorless();
	test_evaluateorgreat();
	test_evaluatearithmetic();
	test_evaluatecompare();

	return 0;
}

void test_pushint(){
	RPNCalc calculator;
	cout << "************TESTING push_int**************" << endl;
	for(int i = 0; i < 3; i++){
		calculator.push_int(i);
	}
	cout << "Expected result:\n2\n1\n0\n";
	cout << "Actual result: " << endl;
	calculator.test_print();
	cout << "***********DONE TESTING push_int**********" << endl << endl;
}

void test_pushstring(){
	RPNCalc calculator;
	cout << "************TESTING push_string***********" << endl;
	string add[3];
	add[0] = "Postion: 0 on the stack";
	add[1] = "Postion: 1 on the stack";
	add[2] = "Postion: 2 on the stack";
	for(int i = 0; i < 3; i++){
		calculator.push_string(add[i]);
	}
	cout << "Expected result:\n"
		 << "{ Postion: 2 on the stack }\n"
		 << "{ Postion: 1 on the stack }\n"
		 << "{ Postion: 0 on the stack }\n";
	cout << "Actual result: " << endl;
	calculator.test_print();
	cout << "***********DONE TESTING push_string*******" << endl << endl;
}

void test_pushbool(){
	RPNCalc calculator;
	cout << "************TESTING push_bool*************" << endl;
	string add[4];
	add[0] = "#t";
	add[1] = "#f";
	add[2] = "#t";
	add[3] = "#f";
	for(int i = 0; i < 4; i++){
		calculator.push_bool(add[i]);
	}
	cout << "Expected result:\n"
		 << "#f\n"
		 << "#t\n"
		 << "#f\n"
		 << "#t\n";
	cout << "Actual result: " << endl;
	calculator.test_print();
	cout << "***********DONE TESTING push_bool*********" << endl << endl;
}

void test_evaluatedrop(){
	RPNCalc calculator;
	cout << "**********TESTING evaluate_drop***********" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_drop();
	cout << "Test 2\n";
	string add[3];
	add[0] = "Postion: 0 on the stack";
	add[1] = "Postion: 1 on the stack";
	add[2] = "Postion: 2 on the stack";
	for(int i = 0; i < 3; i++){
		calculator.push_string(add[i]);
	}
	cout << "Expected result:\n"
		 << "{ Postion: 1 on the stack }\n"
		 << "{ Postion: 0 on the stack }\n";
	cout << "Actual result: " << endl;
	calculator.evaluate_drop();
	calculator.test_print();
	cout << "***********DONE TESTING evaluate_drop*******" << endl << endl;
}

void test_evaluatenot(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_not*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_not();
	cout << "Test 2\n";
	string add[2];
	add[0] = "#t";
	add[1] = "#f";
	for(int i = 0; i < 2; i++){
		calculator.push_bool(add[i]);
	}
	calculator.evaluate_not();
	cout << "Expected result:\n"
		 << "#t\n"
		 << "#t\n";
	cout << "Actual result: " << endl;
	calculator.test_print();
	cout << "\nTest 3\n";
	add[0] = "#t";
	add[1] = "#f";
	for(int i = 0; i < 2; i++){
		calculator.push_string(add[i]);
	}
	cout << "Expected result: Error: datum_not_bool\n"
		 << "Actual result: ";
	calculator.evaluate_not();
	cout << "***********DONE TESTING evaluate_not*******" << endl << endl;
}

void test_evaluateprint(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_print*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_print();
	cout << "Test 2\n";
	string add[2];
	add[0] = "#t";
	add[1] = "#f";
	for(int i = 0; i < 2; i++){
		calculator.push_bool(add[i]);
	}
	cout << "Expected result: #f\n";
	cout << "Actual result: ";
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_print*******" << endl << endl;	
}

void test_evaluateclear(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_clear*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_clear();
	calculator.evaluate_print();
	cout << "Test 2\n";
	string add[2];
	add[0] = "#t";
	add[1] = "#f";
	for(int i = 0; i < 2; i++){
		calculator.push_bool(add[i]);
	}
	cout << "Expected result: empty_stack\n";
	cout << "Actual result: ";
	calculator.evaluate_clear();
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_print*******" << endl << endl;
}

void test_evaluatedup(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_dup*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_dup();
	cout << "Test 2\n";
	for(int i = 0; i < 3; i++){
		calculator.push_int(i);
	}
	cout << "Expected result:\n2\n2\n1\n0\n";
	cout << "Actual result: " << endl;
	calculator.evaluate_dup();
	calculator.test_print();
	cout << "***********DONE TESTING evaluate_dup**********" << endl << endl;
}

void test_evaluateswap(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_swap*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_swap();
	cout << "Test 2\n";
	for(int i = 0; i < 1; i++){
		calculator.push_string("last");
	}
	cout << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_swap();
	cout << "Test 3\n";
	for(int i = 0; i < 3; i++){
		calculator.push_int(i);
	}
	cout << "Expected result:\n1\n2\n0\n{ last }\n";
	cout << "Actual result: " << endl;
	calculator.evaluate_swap();
	calculator.test_print();
	cout << "***********DONE TESTING evaluate_swap**********" << endl << endl;
}

void test_getrequired(){
	RPNCalc calculator;
	cout << "************TESTING get_required*************" << endl;
	cout << "Test 1\n";
	cout << "Expected result: empty_stack\n"
		 << "Actual result: ";
	for(int i = 1; i < 2; i++){
		calculator.push_string("true");
	}
	Datum data1(0);
	Datum data2(0);
	bool ans = calculator.get_required(data1, data2);
	if (ans == false)
		calculator.test_print();
	cout << "\nTest 2\n";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	ans = calculator.get_required(data1, data2);
	string top1 = data1.toString(); 
	string top2 = data2.toString();
	cout << "Expected result:\n"
		 << "Top 1: 2\n"
		 << "Top 2: 1\n"
		 << "Actual result:\n"
		 << "Top 1: " << top1 << endl
		 << "Top 2: " << top2 << endl;
	cout << "***********DONE TESTING get_required**********" << endl << endl;	
}

void test_requiredisInt(){
	RPNCalc calculator;
	cout << "************TESTING required_isInt*************" << endl;
	cout << "Test 1\n";
	cout << "Expected result: false\n"
		 << "Actual result: ";
	Datum data1 = Datum(true);
	Datum data2 = Datum("Hello");
	bool ans = calculator.required_isInt(data1, data2);
	if (ans == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "\nTest 2\n";
	cout << "Expected result: false\n"
		 << "Actual result: ";
	Datum data3 = Datum(1);
	Datum data4 = Datum("Hello");
	ans = calculator.required_isInt(data3, data4);
	if (ans == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "\nTest 3\n";
	cout << "Expected result: true\n"
		 << "Actual result: ";
	Datum data5 = Datum(1);
	Datum data6 = Datum(2);
	ans = calculator.required_isInt(data5, data6);
	if (ans == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "***********DONE TESTING required_isInt**********" << endl << endl;
}

void test_evaluateadd(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_add*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_add();

	cout << "\nTest 2\n";
	cout << "Expected result: empty_stack\n"
		 << "Actual result: ";
	for(int i = 1; i < 2; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_add();

	cout << "\nTest 3\n";
	cout << "Expected result: Error: datum_not_int\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_string("#t");
	}
	calculator.evaluate_add();

	cout << "\nTest 4\n";
	cout << "Expected result: 3\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_add();
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_add**********" << endl << endl;
}

void test_evaluatesubtract(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_subtract*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_subtract();

	cout << "\nTest 2\n";
	cout << "Expected result: empty_stack\n"
		 << "Actual result: ";
	for(int i = 1; i < 2; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_subtract();

	cout << "\nTest 3\n";
	cout << "Expected result: Error: datum_not_int\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_string("#t");
	}
	calculator.evaluate_subtract();

	cout << "\nTest 4\n";
	cout << "Expected result: -1\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_subtract();
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_substract**********" << endl << endl;
}

void test_evaluatemultiply(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_multiply*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_multiply();

	cout << "\nTest 2\n";
	cout << "Expected result: empty_stack\n"
		 << "Actual result: ";
	for(int i = 1; i < 2; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_multiply();

	cout << "\nTest 3\n";
	cout << "Expected result: Error: datum_not_int\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_string("#t");
	}
	calculator.evaluate_multiply();

	cout << "\nTest 4\n";
	cout << "Expected result: 2\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_multiply();
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_multiply**********" << endl << endl;
}

void test_evaluatedivision(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_division*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_division();

	cout << "\nTest 2\n";
	cout << "Expected result: empty_stack\n"
		 << "Actual result: ";
	for(int i = 1; i < 2; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_division();

	cout << "\nTest 3\n";
	cout << "Expected result: Error: datum_not_int\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_string("#t");
	}
	calculator.evaluate_division();

	cout << "\nTest 4\n";
	cout << "Expected result: Error: division by 0\n"
		 << "Actual result: ";
	calculator.push_int(2);
	calculator.push_int(0);
	calculator.evaluate_division();

	cout << "\nTest 5\n";
	cout << "Expected result: 0\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_division();
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_division**********" << endl << endl;
}

void test_evaluatemodulo(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_modulo*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_modulo();

	cout << "\nTest 2\n";
	cout << "Expected result: empty_stack\n"
		 << "Actual result: ";
	for(int i = 1; i < 2; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_modulo();

	cout << "\nTest 3\n";
	cout << "Expected result: Error: datum_not_int\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_string("#t");
	}
	calculator.evaluate_modulo();

	cout << "\nTest 4\n";
	cout << "Expected result: 1\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_modulo();
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_modulo**********" << endl << endl;
}

void test_evaluateless(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_less*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_less();

	cout << "\nTest 2\n";
	cout << "Expected result: empty_stack\n"
		 << "Actual result: ";
	for(int i = 1; i < 2; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_less();

	cout << "\nTest 3\n";
	cout << "Expected result: Error: datum_not_int\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_string("#t");
	}
	calculator.evaluate_less();

	cout << "\nTest 4\n";
	cout << "Expected result: #t\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_less();
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_less**********" << endl << endl;
}

void test_evaluategreat(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_great*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_great();

	cout << "\nTest 2\n";
	cout << "Expected result: empty_stack\n"
		 << "Actual result: ";
	for(int i = 1; i < 2; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_great();

	cout << "\nTest 3\n";
	cout << "Expected result: Error: datum_not_int\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_string("#t");
	}
	calculator.evaluate_great();

	cout << "Test 4\n";
	cout << "Expected result: #f\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_great();
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_great**********" << endl << endl;
}

void test_evaluateequal(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_equal*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_equal();

	cout << "\nTest 2\n";
	cout << "Expected result: empty_stack\n"
		 << "Actual result: ";
	for(int i = 1; i < 2; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_equal();

	cout << "\nTest 3\n";
	cout << "Expected result: #t\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_string("#t");
	}
	calculator.evaluate_equal();
	calculator.evaluate_print();

	calculator.evaluate_clear();

	cout << "\nTest 4\n";
	cout << "Expected result: #f\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_equal();
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_equal**********" << endl << endl;
}

void test_evaluateorless(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_orless*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_orless();

	cout << "\nTest 2\n";
	cout << "Expected result: empty_stack\n"
		 << "Actual result: ";
	for(int i = 1; i < 2; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_orless();

	cout << "\nTest 3\n";
	cout << "Expected result: Error: datum_not_int\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_string("#t");
	}
	calculator.evaluate_orless();

	calculator.evaluate_clear();

	cout << "Test 4\n";
	cout << "Expected result: #t\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_orless();
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_orless**********" << endl << endl;
}

void test_evaluateorgreat(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_orgreat*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	calculator.evaluate_orgreat();

	cout << "\nTest 2\n";
	cout << "Expected result: empty_stack\n"
		 << "Actual result: ";
	for(int i = 1; i < 2; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_orgreat();

	cout << "\nTest 3\n";
	cout << "Expected result: Error: datum_not_int\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_string("#t");
	}
	calculator.evaluate_orgreat();

	calculator.evaluate_clear();

	cout << "Test 4\n";
	cout << "Expected result: #f\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_orgreat();
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_orgreat**********" << endl << endl;
}

void test_evaluatearithmetic(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_arithmetic*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	string command = "+";
	calculator.evaluate_arithmetic(command);

	cout << "\nTest 2\n";
	cout << "Expected result: Error: datum_not_int\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_string("#t");
	}
	calculator.evaluate_arithmetic(command);

	cout << "Test 3\n";
	cout << "Expected result: 1\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	command = "mod";
	calculator.evaluate_arithmetic(command);
	calculator.evaluate_print();

	command = "-";
	cout << "\nTest 4\n";
	cout << "Expected result: -1\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	calculator.evaluate_arithmetic(command);
	calculator.evaluate_print();
	cout << "*********DONE TESTING evaluate_arithmetic********" << endl << endl;
}

void test_evaluatecompare(){
	RPNCalc calculator;
	cout << "************TESTING evaluate_compare*************" << endl;
	cout << "Test 1\n"
		 << "Expected result: empty_stack\n"
		 << "Actual result: ";
	string command = "+";
	calculator.evaluate_compare(command);

	cout << "\nTest 2\n";
	cout << "Expected result: Error: datum_not_int\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_string("#t");
	}
	command = "<";
	calculator.evaluate_compare(command);

	cout << "Test 3\n";
	cout << "Expected result: #f\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	command = ">=";
	calculator.evaluate_compare(command);
	calculator.evaluate_print();

	cout << "\nTest 4\n";
	cout << "Expected result: #f\n"
		 << "Actual result: ";
	for(int i = 1; i < 3; i++){
		calculator.push_int(i);
	}
	command = "==";
	calculator.evaluate_compare(command);
	calculator.evaluate_print();
	cout << "***********DONE TESTING evaluate_compare**********" << endl << endl;
}

void test_run(){
	RPNCalc calculator;
	calculator.run();
}