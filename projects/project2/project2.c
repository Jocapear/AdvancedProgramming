#include <stdio.h>

int brattleship(int r, int c, int w){
	int rowi;
	int turns = 0;
	for (rowi = 1; rowi <= r; ++rowi)
	{
		//printf("We are in %d\n",rowi );
		if (rowi == r) //On the last row
		{
			if (w == 1)
			{
				//printf("W = 1\n");
				turns += c;
			}else if((float)w <= ((float)c/2)){
				printf("Less or equal than the half\n");
				turns += c-(w-1);
			}else{
				printf("Greater than the half\n");
				if (w == c)
				{
					turns += w;
				}else{
					turns += w+1;
				}	
			}
		}else{ //Any other row
			if (w == 1)
			{
				turns += c;
			}else if((float)w <= ((float)c/2)){
				turns += c-((w*2)-2);
			}else{
				turns += 1;
			}
		}
	}
	return turns;
}

int main(int argc, char const *argv[])
{
	//char *fileName = "A-small-practice.in";
	//FILE *myFile = fopen(fileName, "r");

	int r = 2;
	int c = 4;
	int w = 2;
	printf("%d\n", brattleship(r,c,w));
	return 0;
}