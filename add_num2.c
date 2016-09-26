#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int input[100];
        int i=0;
         for(i=0;i<100; i++)
            {
              input[i]=rand()%10;              
			}
int sum1=0,sum2=0;
clock_t start, end;
double cpu_time_used;

start = clock();
… /* Do the work. */
#pragma omp parallel num_threads(2)
{
	int id = omp_get_thread_num();
                 if(id==0){
		for (i=0;i<100;i=i+2)
		{
			sum1=sum1+input[i];
		}}
               else
                 {
                  for (i=1;i<100;i=i+2)
		{
			sum1=sum1+input[i];
		}
                       }
		
}
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("\n%lf time used \n",cpu_time_used);
printf("sum = %d\n",sum1+sum2);
}