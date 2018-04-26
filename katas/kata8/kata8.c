#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int * moviesLenght[10] = {60,180,120,120,180,120,60,120,60,60};
	int flightLenght = 180;

    HashInt hash;
	hashInit(&hash, 100);

	for (int i = 0; i < sizeof(moviesLenght)/sizeof(int); ++i)
	{
		if(moviesLenght[i]) < flightLenght{
			hashInsert(&hash, moviesLenght[i], moviesLenght[i]);
		}
	}

	for (int i = 0; i < sizeof(moviesLenght)/sizeof(int); ++i)
	{
		int remainingTime = flightLenght - moviesLenght[i]; 
		if (hashGet(&hash, remainingTime) != null){
			if (hashGet(&hash, remainingTime) != moviesLenght[i])
			{
				return true;
			}
		}
	}

	return false;
}