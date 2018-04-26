#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int* makeBinary(int n){
	int accum = n;
	int * binaryArray[8] = {0,0,0,0,0,0,0,0};
	for (int i = 0; i < 8; ++i)
	{
	 	int position = pow(2, 7-i);
	 	if (accum >= position)
	 	{
	 	 	binaryArray[i] = 1;
	 	 	accum -= position;
	 	}else{
	 		binaryArray[i] = 0;
	 	}
	}

	return *binaryArray;
}
int main()
{
	int * data[3] = {197, 130, 1};
	for (int i = 0; i < 3; ++i)
	{
		makeBinary(data[i]);
	}
}