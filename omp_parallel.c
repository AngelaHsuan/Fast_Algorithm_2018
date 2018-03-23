#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>


//編譯器選項-> -fopenmp --> So that you can use the parallel calculation

int main()
{
	int i, j, k, N=100000000;
	double a = 1.234, b = 2.345;
	double ot1, ot2;
	clock_t t1, t2;
	ot1 = omp_get_wtime();
	
	/*	
	#pragma omp parallel	//Can only effect on the code right below it
	printf("Hello World\n");
	printf("Hello me\n");	//This will not be effected
	
	return 0;
	*/
	
//----------------------------------------------------------------------------------------------------------
	
	/*
	#pragma omp parallel	//Do parallel calculation of the code below
	{
		printf("Hello World (%d,%d,%f)\n",omp_get_thread_num(),omp_get_num_threads(),omp_get_wtime()-ot1);
		printf("Hello me (%d,%d,%f)\n",omp_get_thread_num(),omp_get_num_threads(),omp_get_wtime()-ot1);
	}
	printf("-------------------------------------------------------------\n");
	#pragma omp parallel num_threads(4)	//Do parallel calculation with 4 threads
	{
		printf("Hello World (%d,%d,%f)\n",omp_get_thread_num(),omp_get_num_threads(),omp_get_wtime()-ot1);
		printf("Hello me (%d,%d,%f)\n",omp_get_thread_num(),omp_get_num_threads(),omp_get_wtime()-ot1);
	}
	
	return 0;
	*/
//-----------------------------------------------------------------------------------------------------
	
	/*
	j = 0;
	#pragma omp parallel for//沒有 for 是8個人同時開始跑迴圈->所有人都會拿到i=0 並共享同一個i
	for(i=0;i<10;++i)
	{
		j = 0;
		//printf("i = %d j = %d thread = %d \n",i,j,omp_get_thread_num());
		j = i;		//total works ---> j=0, j=1, j=2, ...,j=9
		printf("i = %d j = %d thread = %d \n",i,j,omp_get_thread_num());
	}
	printf("j = %d\n",j);
	
	return 0;
	
	//Q:用上面兩行顯示分別會得出不同的j?  
	*/
	
//--------------------------------------------------------------------------------------------------
	
	/*
	j = 0;
	for(i=0;i<=10;++i)
	{
		j += i;
	}
	printf("sum(1..10) = %d\n",j);
	
	printf("-----------------------------------------\n");
	
	j = 0;
	#pragma omp parallel for //在取的過程中可能會取到同一個j 所以答案可能會錯 =口= 
	for(i=0;i<=10;++i)
	{
		//printf("i = %d j = %d thread = %d \n",i,j,omp_get_thread_num());
		j += i;
		printf("i = %d j = %d thread = %d \n",i,j,omp_get_thread_num());
	}
	printf("sum(1..10) = %d\n",j);
	
	printf("-----------------------------------------\n");
	
	j = 0;
	#pragma omp parallel for reduction(+:j)	//avoid taking same j
	for(i=0;i<=10;++i)
	{
		//printf("i = %d j = %d thread = %d \n",i,j,omp_get_thread_num());
		j += i;
		printf("i = %d j = %d thread = %d \n",i,j,omp_get_thread_num());
	}
	printf("sum(1..10) = %d\n",j);
	
	return 0;
	*/
	
//----------------------------------------------------------------------------------------------------
	
	//#pragma omp parallel for
	//#pragma omp parallel for
	for(k=0;k<=1000;++k)
	{
		j = 0;
		#pragma omp parallel for
		for(i=0;i<=10;++i)
		{
			j += i;
		}
		if (j!=55)
		{
			printf("wrong, k = %d thread = %d\n",k,omp_get_thread_num());
		} 
	}
	
	//#pragma omp parallel for private(i)
	//#pragma omp parallel for
	for(k=0;k<=1000;++k)
	{
		j = 0;
		#pragma omp parallel for private(i)
		for(i=0;i<=10;++i)
		{
			j += i;
		}
		if (j!=55)
		{
			printf("wrongwrong, k = %d thread = %d\n",k,omp_get_thread_num());
		} 
		
	}
	
	//#pragma omp parallel for reduction(+:j)
	#pragma omp parallel for private(k,j)
	for(k=0;k<=1000;++k)
	{
		j = 0;
		#pragma omp parallel for reduction(+:j)	//確認不會拿到同一個j but will spend more time
		for(i=0;i<=10;++i)
		{
			j += i;
		}
		if (j!=55)
		{
			printf("wrongwrongwrong, k = %d thread = %d\n",k,omp_get_thread_num());
		} 
	}
	return 0;
	
	//From the above we can find that 
	//only when we use reduction(+:j) can we confirm not taking the same j
	
	//#pragma omp parallel for private(k,j) -> every thread use respective j and k
	//Ex:thread 0 : j0, k0 ; thread 0 : j0, k0 ; thread 1 : j1, k1 ; .....
	//#pragma omp parallel for reduction(+:j) -> you can't take each others j
	
	
//-----------------------------------------------------------------------------------------------------------
	
	/*沒上到???????????????????? 
	
	t1 = clock();
	for(i=0;i<N;++i) {
		a = a*b;
		b = a/b;
		a = a/b;
	}
	t2 = clock();
	printf("a = %f, b = %f\n", a, b);
	printf("parallel time:%f\n",(t2-t1)/(double) CLOCKS_PER_SEC);
	
	t1 = clock();
	#pragma omp parallel for num_threads(4)
	for(i=0;i<N;++i) {
		a = a*b;
		b = a/b;
		a = a/b;
	}
	t2 = clock();
	printf("a = %f, b = %f\n", a, b);
	printf("parallel time:%f\n",(t2-t1)/(double) CLOCKS_PER_SEC);
	*/
	
	return 0;
}
