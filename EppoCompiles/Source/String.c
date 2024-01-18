#include "String.h"

#include <stdio.h>
#include <stdlib.h>

string_t* str_createEmpty()
{
	string_t* str = malloc(sizeof(string_t));

	// Null check
	if (str == NULL)
		return NULL;
	
	// Null initialization
	str->data = NULL;
	str->size = 0;

	// Return new string
	return str;
}

string_t* str_create(const char* data)
{
	string_t* str = malloc(sizeof(string_t));

	// Null check
	if (str == NULL)
		return NULL;

	// Copy string data
	str->data = strdup(data);
	
	// Set size
	str->size = (unsigned int)strlen(data) + 1;
	
	// Return new string
	return str;
}

void str_free(string_t* str)
{
	free(str->data);
	free(str);
}

void str_setData(string_t* str, const char* data)
{
	size_t size = strlen(data) + 1;
	if (size == str->size)
	{
		str->data = strdup(data);
	} else
	{
		str_free(str);
		str = str_create(data);
	}
}
