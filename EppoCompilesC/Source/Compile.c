#include "Compile.h"

#include "List.h"

#include <stdio.h>
#include <ctype.h>

void compile(string_t* str)
{
	// Print file
	printf("%s\n", str->data);
	
	// Lexical analysis
	linkedList_t* token = ll_createList();

	// Loop over all characters
	int i = 0;
	while (i < str->size)
	{
		// Start of token // Cannot be numeric
		if (isalpha(str->data[i]))
		{
			ll_prependNode(token, str->data[i]);
			i++;
			
			// Get rest of token
			while (isalnum(str->data[i]))
			{
				ll_prependNode(token, str->data[i]);
				i++;
			}

			// Add to list of tokens
			ll_printList(token);
		}


		// Increment character pointer
		i++;
	}
}