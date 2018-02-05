#include <stdio.h>

int judgeRouteCircle(char * s){
	//int l, r, u, d = 0;
	//int x = 0;
	int y = 0;
	//int size = sizeof(s)/sizeof(char);
	int i = 0;
	while(true)
	{
		//printf("%c\n",(char)s[i] );
		if (s[i] == 'L')
		{
			x -= 1;
			//l += 1;
		}
		else if (s[i] == 'R')
		{
			x += 1;
			//r += 1;
		}
		else if (s[i] == 'D')
		{
			y -= 1;
			//d += 1;
		}
		else if (s[i] == 'U')
		{
			y += 1;
			//u += 1;
		}else{
			break;
		}
		i++;
	}
	if (x == 0 && y == 0)
	{
		printf("true\n");
		return true;
	}else{
		printf("false\n");
		return false;
	}
}

int main(){
	//char route[] = "UD";
	//char route[] = "LL";
	char route[] = "LRLRLRLRLRLRUDUDUDUDUD";
	judgeRouteCircle(route);
	return 0;
}