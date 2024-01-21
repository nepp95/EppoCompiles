#include <stdio.h>
#include <stdlib.h>

#include "Compile.h"
#include "Utility.h"

int main(int argc, char** argv)
{
	// No file input
	if (argc <= 1)
	{
		printf("No file input");
		return 1;
	}

	// Open file // TODO: Should be pointer because of size
	string_t* str = readFile(argv[1]);
	if (str == NULL)
	{
		printf("Error reading input file");
		return 1;
	}

	// Compile
	compile(str);

	// Linking
	// To be continued...

	return 0;
}