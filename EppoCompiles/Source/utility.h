#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	void* Buffer;
	size_t Size;
} FileHandle;

FileHandle ReadFile(const char* filepath);
