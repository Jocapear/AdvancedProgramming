#include <stdio.h>
#define MAX_INT 2147483647

int main()
{
	int a = 250;
	//long int d = a * a !! Da de resultado un 1 si on hago cast por OVERFLOW
	long int d = a * (long)a; //No importa a que "a" le haga el cast
	int j=0,k=0,l=0;
	int *p;
	float f= 4.67;
	int e = 4;
	//int c = f + e; !!Transforma el resultado a un float y luego le corta el decimal, hace la operacion decimal que no queremos
	int c = (int)f + e;
	p = &a;
	*p = 400;
	p++;
	*p = 5555;

	//printf("a = %d\nd = %ld\nf = %f\ne = %d\nc = %d\n ",a,d,f,e,c);
	printf("a = %d\np = %p\nj = %d\nk = %d\nl = %d\n",a,p,j,k,l);
	return 0;
}