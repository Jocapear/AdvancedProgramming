#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int doFullName(char * firstName, char *lastName, char **fullNameValue){
	int sizeFirstName = strlen(firstName);
	int sizeLastName = strlen(lastName);
	int sizeFullName = sizeFirstName + sizeLastName + 1;

	char *fullName = (char *) malloc(sizeFullName * sizeof(char));

	strcpy(fullName, firstName);
	strcpy(fullName + sizeFirstName," ");
	strcpy(fullName + sizeFirstName + 1, lastName);
	*fullNameValue = fullName;
}

int main()
{
	char firstName[] = "José Carlos";
	char lastName[] = "Peñuelas Armenta";
	char *fullName;
	doFullName(firstName, lastName, &fullName);
	printf("%s\n", fullName);
	free(fullName);
	return 0;
}