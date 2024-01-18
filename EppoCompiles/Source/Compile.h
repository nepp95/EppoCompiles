#pragma once

#include "String.h"

typedef enum
{
	Identifier,
	Keyword,
	Type
} tokenType_t;

typedef struct
{
	tokenType_t type;
	string_t value;
} token_t;

void compile(string_t* str);