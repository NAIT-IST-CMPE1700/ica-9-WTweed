#ifndef LINBKEDLISTH
#define LINKEDLISTH

#pragma once

struct node 
{
	char* name;
	int mark;
	int ID;
	struct node* next;
};
 
typedef enum
{
	false,true
}bool;


typedef struct node* ptr;


#endif