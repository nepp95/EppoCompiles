#pragma once

#include <string.h>

typedef struct
{
	char* data;
	unsigned int size;
} string_t;

string_t* str_createEmpty();
string_t* str_create(const char* data);
void str_free(string_t* str);

void str_setData(string_t* str, const char* data);
