#include <stdio.h>


int greatestPowerOfTwo(int n){
	if (n == 1){
		return 1;
	}

	int temp = 1;
	while(temp*2 <= n){
		temp *= 2;
	}
	return temp;
}

int lookAhead(int stones, int turn){
	//printf("I will pass the turn now to player %d\n", turn);
	int stonesPicked = greatestPowerOfTwo(stones);
	//printf("Player %d will pick %d rocks\n",turn, stonesPicked);
	if (stones == stonesPicked)
	{
		if (turn == 1)
		{
			return 1;
		}else{
			return 0;
		}
	}else{
		int remainingStones = stones - stonesPicked;
		//printf("There are %d rocks\n",remainingStones);
		while(remainingStones == greatestPowerOfTwo(remainingStones)){
			//printf("Player %d realized its lost\n",turn );
			if (stonesPicked == 1)
			{
				//printf("Oh noes, there are no more options for player %d\n", turn);
				if (turn == 1)
				{
					//printf("Player %d surrenders this match\n",turn);
					return 0;
				}else{
					//printf("Player %d surrenders this match\n",turn);
					return 1;
				}
			}else{
				//printf("Player %d will try to reduce the rocks picked\n", turn);
				stonesPicked /= 2;
				remainingStones = stones - stonesPicked;
			}
		}
		if (turn == 1)
		{
			return lookAhead(remainingStones, 2);
		}else{
			return lookAhead(remainingStones, 1);
		}
	}
}

int main(){
	//printf("%d\n", greatestPowerOfTwo(12));
	int n = 8; //CHANGE INPUT HERE
	int i = 1;
	for (i = 1; i <= n; i *= 2)
	{
		//printf("Trying with %d rocks\n", i);
		if (i == n)
		{
			printf("%d\n", 1);
			printf("%d\n", n);
			return 0;
		}
		else{
			if (n-i == greatestPowerOfTwo(n-i))
			{
				//printf("%d\n", 2);
				//return 0;
			}else if(lookAhead(n-i, 2) == 1){
				//printf("Player 1 wins this one with %d rocks\n", i);
				printf("%d\n", 1);
				printf("%d\n", i);
				return 0;
			}
		}
	}
	printf("%d\n", 2);
	return 0;
}