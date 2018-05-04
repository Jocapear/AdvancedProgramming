#include <stdio.h>
#define MAX 500
int array[MAX +10];
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		int n;
		scanf("%d",&n);
		int accum = 0;
		int i;
		for(i=0;i<n;i++){
			scanf("%d",&array[i]);
			accum = accum^array[i];
		}
		if(accum == 0)
			printf("First\n");
		else{
			if(n%2==0)
				printf("First\n");
			else
				printf("Second\n");
		}
		t--;
	}
	return 0;
}