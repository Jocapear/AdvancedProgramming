#include <stdio.h>



int main(){
	//int A[] = {12, 28, 46, 32, 50};  
	//int B[] = {50, 12, 32, 46, 28};

	int A[] = {12, 28, 12, 32, 50};
	int B[] = {50, 12, 32, 12, 28};

	int sizeA = (sizeof(A)/sizeof(int));
	int sizeB = (sizeof(B)/sizeof(int));

	int answer[sizeA];

	for (int i = 0; i < sizeA; ++i)
	{
		for (int j = 0; j < sizeB; ++j)
		{
			if (A[i] == B[j])
			{
				int found = 0;
				for (int k = 0; k < sizeA; ++k)
				{
					if (answer[k] == j)
					{
						found = 1;
					}
				}

				if (found == 0)
				{
					answer[i] = j;
				}
			}
		}
	}

	for (int i = 0; i < sizeA; ++i)
	{
		printf("[%d],", answer[i] );
	}
	
	return 0;
}