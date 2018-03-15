#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "hash.h"

/* Add function signatures here */
void printFrequencies(char *key,int value) {
	printf("%s %d \n", key, value);
}

int main(int argc, char **argv)
{
	int character;
	char word[250];
	int j;
	int *value;
	int realValue;

	HashInt hash;
	hashInit(&hash, 100);
	while (!feof(stdin))
	{
		character = fgetc(stdin);
		if (isalnum(character))
		{
			word[j] = (char)tolower(character);
			j++;
		}
		else
		{
			word[j] = '\0';
			if (j > 0)
			{
			//printf("%s\n", word);
			value = hashGet(&hash, word);

			if (value == NULL)
			{
				realValue = 1;
			}
			else
			{
				realValue = *value + 1;
			}
				hashInsert(&hash, word, realValue);
			}
			j = 0;
		}
	}
	forEach(&hash, printFrequencies);
	return 0;
}