#include "utility.h"

FileHandle ReadFile(const char* filepath)
{
	FileHandle fileHandle;
	fileHandle.Buffer = NULL;
	fileHandle.Size = 0;

	// Open file
	FILE* f = fopen(filepath, "r");
	if (f == NULL)
	{
		printf("Error opening file");
		return fileHandle;
	}

	// Get file size
	fseek(f, 0, SEEK_END);
	fileHandle.Size = ftell(f);
	rewind(f);

	// Read file
	fileHandle.Buffer = malloc(fileHandle.Size + 1);
	if (!fileHandle.Buffer)
		return fileHandle;

	if (fread(fileHandle.Buffer, fileHandle.Size, 1, f) != 1 && !feof(f))
	{
		printf("Error reading file");

		free(fileHandle.Buffer);
		fileHandle.Buffer = NULL;

		fclose(f);
	}

	return fileHandle;
}