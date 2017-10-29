###########################################################################
##                  Makefile for PROJ1 (RPN Calc)                    ##
###########################################################################
CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra
LDFLAGS  = -g3

CalcYouLater: Datum.o DatumStack.o RPNCalc.o main.o
	${CXX} ${LDFLAGS} -o CalcYouLater Datum.o \
						DatumStack.o RPNCalc.o main.o

DatumStack.o:     DatumStack.cpp DatumStack.h Datum.h
RPNCalc.o: RPNCalc.cpp RPNCalc.h DatumStack.h
main.0: RPNCalc.h

clean:
	rm -rf grocerySim *.o *.dSYM

provide:
	provide comp15 proj1 DatumStack.h DatumStack.cpp \
							testDatumStack.cpp RPNCalc.h RPNCalc.cpp \
							testRPNCalc.cpp main.cpp README Makefile
