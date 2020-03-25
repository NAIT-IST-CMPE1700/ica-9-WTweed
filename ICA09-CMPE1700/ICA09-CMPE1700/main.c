#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void main(int argc, char** argv)
{

	ptr ID = NULL;
	ptr Grades = NULL;

	bool exitM = false;

	char* Names[10]={ "Will", "Jeremy", "Emily", "Wyatte", "Josh", "Jo-Anne", "Greg", "Jake", "Carol", "Tyler" };
	int IDs[10];
	int GradesArray[10];
	
	CreateIDs(IDs);
	CreateGrades(GradesArray);

	for (int x = 0; x < 10; x++)
	{
		ID = AddID(ID, Names, IDs, GradesArray, x);
		Grades = AddGrades(Grades, Names, IDs, GradesArray, x );
	}


	while (!exitM)
	{
		exitM = Menu(ID, Grades);
	}

	FreeMem(ID, Grades);

	exit(EXIT_SUCCESS);
}