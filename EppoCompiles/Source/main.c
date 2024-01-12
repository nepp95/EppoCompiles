#include <stdio.h>
#include <stdlib.h>

#include "utility.h"

int main(int argc, char** argv)
{
	// No file input
	if (argc <= 1)
	{
		printf("No file input");
		return 1;
	}

	// Open file
	FileHandle fileHandle = ReadFile(argv[1]);
	if (!fileHandle.Buffer)
	{
		printf("Error reading file");
		return 1;
	}

	// Print file
	for (int i = 0; i < fileHandle.Size; i++)
		printf("%c", ((char*)fileHandle.Buffer)[i]);

	return 0;
}