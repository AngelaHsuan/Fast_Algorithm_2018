#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()

// ----------------------Calculating the computing time of adding------------------------
{
	clock_t t1, t2;				//variables for computing clocks
	double a=1.234, b=2.456,c;
	double T1,T2;
	int i, j, k, N=100000000;
	t1 = clock();
	for(i=0;i<N;++i)
	{
		a = a+b;		//
		b = a-b;		//
		a = a-b;		//changing the value of a&b
	}
	t2 = clock();
	T1 = (t2-t1)/(double) CLOCKS_PER_SEC;
	printf("(+,-) time:%f\n",T1);
	printf("(a,b)=%f %f\n", a,b);
	
	t1 = clock();
	for(i=0;i<N;++i)
	{
		a = a+b;		//
		b = a-b;		//
		a = a-b;		//
		a = a+b;		//
		b = a-b;		//
		a = a-b;		//changing the value of a&b
	}
	t2 = clock();
	T2 = (t2-t1)/(double) CLOCKS_PER_SEC;
	printf("(+,-) time:%f\n",T2);
	printf("(a,b)=%f %f\n", a,b);
	
	printf("real (+,-) time:%f\n",(T2-T1)/3.0);
	printf("(a,b)=%f %f\n", a,b);
	
	system("pause");
	
// -----------------Calculating the computing time of exchanging----------------------
	
	t1 = clock();
	for(i=0;i<N;++i)
	{
		c = b;		//
		b = a;		//
		a = c;		//changing the value of a&b
		c = b;		//
		b = a;		//
		a = c;
	}
	t2 = clock();
	T1 = (t2-t1)/(double) CLOCKS_PER_SEC;
	printf("(+,-) time:%f\n",T1);
	printf("(a,b)=%f %f\n", a,b);
	
	t1 = clock();
	for(i=0;i<N;++i)
	{
		c = b;		//
		b = a;		//
		a = c;	
	}
	t2 = clock();
	T2 = (t2-t1)/(double) CLOCKS_PER_SEC;
	printf("(+,-) time:%f\n",T2);
	printf("(a,b)=%f %f\n", a,b);
	
	printf("real (+,-) time:%f\n",(T2-T1)/3.0);
	printf("(a,b)=%f %f\n", a,b);
	
	system("pause");
	
// -----------------Calculating the computing time of multiplying-------------------
	
	for(i=0;i<N;++i)
	{
		a = a*b;
		b = a/b;
		a = a/b;
	}
	t2 = clock();
	printf("(*,/) time:%f\n",(t2-t1)/(double) CLOCKS_PER_SEC/3.0);
	printf("(a,b)=%f %f\n", a,b);
	
// ----------------Calculating the computing time of sine function------------------
	
	for(i=0;i<N;++i)
	{
		a = sin(b);
		b = sin(a);
	}
	t2 = clock();
	printf("(sin) time:%f\n",(t2-t1)/(double) CLOCKS_PER_SEC/2.0);
	printf("(a,b)=%f %f\n", a,b);
	srand(time(NULL));
	short r;

	t1 = clock();
	for(i=0;i<N;i++)
	{
		r = rand();
	}
	t2 = clock();
	printf("(rand) time:%f\n",(t2-t1)/(double) CLOCKS_PER_SEC);
	printf("r=%d\n", r);

	//short A[10000][10000];
	t1 = clock();
	for(i=0;i<N;i++)
	{
		r = rand();
	}
	t2 = clock();
	printf("(rand) time:%f\n",(t2-t1)/(double) CLOCKS_PER_SEC);
	//printf("r=%d\n", A[9999][9999]);

	return;
} 
