#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"

CreateIDs(int* createIDs)
{

	srand(time(0));

	for (int x = 0; x < 10; x++)
	{
		createIDs[x] = rand() % (9999999999);
	}
}

CreateGrades(int* createGrades)
{

	srand(time(0));

	for (int x = 0; x < 10; x++)
	{
		createGrades[x] = rand() % (100);
	}
}
ptr CreateNode()
{
	ptr X;

	X = (ptr)malloc(sizeof(struct node));

	X->next = NULL;

	return X;
}

ptr AddID(ptr head, char* addName[10], int* addID[10], int* addGrade[10], int x )
{
	ptr placeHold, current;

	placeHold = CreateNode();
	placeHold->name = addName[x];
	placeHold->ID = addID[x];
	placeHold->mark = addGrade[x];


	if (head == NULL )
	{
		head = placeHold;
	}
	if (addID[x] > head->ID)
	{
		current = head;

		while (current->next != NULL && addID[x] > current->next->ID)
		{
			current = current->next;
		}

		placeHold->next = current->next;
		current->next = placeHold;
	}
	if (addID[x] < head->ID)
	{
		placeHold->next = head;
		head = placeHold;
	}

	return head;
}
ptr AddGrades(ptr head, char* addName[10], int* addID[10], int* addGrade[10], int x)
{
	ptr placeHold, current;

	placeHold = CreateNode();
	placeHold->name = addName[x];
	placeHold->ID = addID[x];
	placeHold->mark = addGrade[x];


	if (head == NULL)
	{
		head = placeHold;
	}
	if (addGrade[x] < head->mark)
	{
		current = head;

		while (current->next != NULL && (addGrade[x] < current->next->mark|| addGrade[x] == current->next->mark))
		{
			current = current->next;
		}

		placeHold->next = current->next;
		current->next = placeHold;
	}
	if (addGrade[x] > head->mark)
	{
		placeHold->next = head;
		head = placeHold;
	}

	return head;
}

bool Menu(ptr headID, ptr headGrades)
{
	int menuOption;

	printf("1. Display list in order of Id's\n2. Display list in descending order of Marks\n");
	printf("3. Display the names, marks and rank of a person given the ID\n");
	printf("4. Display the names and marks of all person above a threshold marks value\n5. Exit\n\nYour Selection: ");
	
	if (scanf_s("%d", &menuOption, sizeof(int)))
	{

		switch (menuOption)
		{
		case 1:
		{
			DisplayList(headID);
				return false;
		}
		case 2:
		{
			DisplayList(headGrades);
			return false;
		}
		case 3:
		{
			DisplayByID(headID);
			return false;
		}
		case 4:
		{
			DisplayThreshold(headGrades);
			return false;
		}
		case 5:
		{
			return true;
		}
		default:
		{
			printf("\nPlease Select Valid Option....\n---------------------------------------\n\n");
			return false;
		}

		}
	}
	else
	{
		printf("\nPlease Select Valid Option....\n---------------------------------------------\n\n");
		return false;
	}
	
}
DisplayList(ptr displayID)
{
	ptr current;
	current = displayID;

	while (current != NULL)
	{
		printf("\nID: %d  Name: %s  Grade: %d", current->ID, current->name, current->mark);
		current = current->next;
	}

	printf("\n------------------------\n\n");
}
DisplayByID(ptr displayByID)
{
	int IDSelection;
	ptr current;
	current = displayByID;

	printf("Select ID: ");
	scanf_s("%d", &IDSelection, sizeof(int));

	while (current  != NULL)
	{
		if (current->ID == IDSelection)
		{
			printf("\nName: %s  Grade: %d  \n---------------------------------\n\n", current->name, current->mark);
			break;
		}
		if (current->ID != IDSelection)
		{
			current = current->next;
		}
	}
	if (current == NULL)
	{
		printf("\nID does not exist!\n-------------------------\n\n");
	}
}
DisplayThreshold(ptr displayThreshold)
{
	int threshSelection;
	ptr current;
	current = displayThreshold;

	printf("Select Threshold: ");
	scanf_s("%d", &threshSelection, sizeof(int));

	while (current != NULL)
	{
		if (current->mark > threshSelection)
		{
			printf("\nName: %s  Grade: %d  ", current->name, current->mark);
		}
		current = current->next;
	}
	printf("\n-----------------------------------\n\n");
}
FreeMem(ptr freeID, ptr freeGrades)
{
	ptr current = freeID;
	ptr current2 = freeGrades;

	ptr x, y;

	while (current != NULL)
	{
		x = current->next;
		y = current2->next;

		free(current);
		free(current2);

		current = x;
		current2 = y;
	}
}

