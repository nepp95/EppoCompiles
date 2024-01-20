#include "List.h"

#include <stdio.h>
#include <stdlib.h>

linkedList_t* ll_createList()
{
	linkedList_t* list = malloc(sizeof(linkedList_t));
	list->head = NULL;

	return list;
}

void ll_freeList(linkedList_t* list)
{
	listNode_t* current = list->head;
	while (current != NULL)
	{
		void* temp = current->next;
		free(current);
		current = temp;
	}
}

void ll_printList(linkedList_t* list)
{
	listNode_t* current = list->head;
	while (current != NULL)
	{
		printf("%c", current->value);
		current = current->next;
	}
	printf("\n");
}

listNode_t* ll_prependNode(linkedList_t* list, char data)
{
	listNode_t* node = malloc(sizeof(listNode_t));
	if (node == NULL)
		return NULL;

	node->value = data;

	if (list->head == NULL)
		node->next = NULL;
	else
		node->next = list->head;

	list->head = node;

	return node;
}

listNode_t* ll_appendNode(linkedList_t* list, char data)
{
	
}
