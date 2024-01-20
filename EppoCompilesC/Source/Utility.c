#include "Utility.h"

// fileHandle_t readFile(const char* filepath)
// {
// 	fileHandle_t fileHandle;
// 	fileHandle.buffer = NULL;
// 	fileHandle.size = 0;

// 	// Open file
// 	FILE* f = fopen(filepath, "r");
// 	if (f == NULL)
// 		return fileHandle;

// 	// Get file size
// 	fseek(f, 0, SEEK_END);
// 	fileHandle.size = ftell(f);
// 	rewind(f);

// 	// Allocate buffer
// 	fileHandle.buffer = malloc(fileHandle.size + 1);
// 	if (fileHandle.buffer == NULL)
// 		return fileHandle;

// 	// Read file
// 	if (fread(fileHandle.buffer, fileHandle.size, 1, f) != 1 && !feof(f))
// 	{
// 		printf("Error reading file!");

// 		free(fileHandle.buffer);
// 		fileHandle.buffer = NULL;

// 		fclose(f);

// 		return fileHandle;
// 	}

// 	// Close file
// 	fclose(f);

// 	return fileHandle;
// }

string_t* readFile(const char* filepath)
{
	char* buffer;

	// Open file
	FILE* f = fopen(filepath, "r");
	if (f == NULL)
		return NULL;

	// Get file size
	fseek(f, 0, SEEK_END);
	long size = ftell(f) + 1;
	
	buffer = malloc(size);
	if (buffer == NULL)
		return NULL;
	
	rewind(f);

	// Read file
	if (fread(buffer, size, 1, f) != 1 && !feof(f))
	{
		printf("Error reading file!");

		free(buffer);
		fclose(f);

		return NULL;
	}

	// Close file
	fclose(f);

	// Return buffer as string
	return str_create(buffer);
}
