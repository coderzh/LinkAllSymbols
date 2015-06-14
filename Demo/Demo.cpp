// Test.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include "LinkAllSymbols.h"

// For test /OPT:NOREF Option
int UnusedFunction()
{
	printf("Never b called");
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

