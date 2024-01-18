#pragma once

#include "String.h"

#include <stdio.h>
#include <stdlib.h>

// typedef struct
// {
// 	void* buffer;
// 	size_t size;
// } fileHandle_t;

// fileHandle_t readFile(const char* filepath);
string_t* readFile(const char* filepath);
