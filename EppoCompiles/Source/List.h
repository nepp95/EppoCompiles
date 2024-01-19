#pragma once

typedef struct
{
	void* prev;
	void* next;
	char value;
} listNode_t;

typedef struct
{
	listNode_t* head;
	listNode_t* tail;
} linkedList_t;

linkedList_t* ll_createList();
void ll_freeList(linkedList_t* list);
void ll_printList(linkedList_t* list);

listNode_t* ll_prependNode(linkedList_t* list, char data);
listNode_t* ll_appendNode(linkedList_t* list, char data);
