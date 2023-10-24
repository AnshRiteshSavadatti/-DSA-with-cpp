// time-analysis.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define N 1000
#define iter 1000000

void array_sum(int a[])
{
   int sum = 0;
   int i;
   for(i = 0; i < N; i++)
    sum = sum  + a[i];
}

int main()
{
    clock_t start, end;

    int a[N];
    int i;
    for(i = 0; i < N; i++)
        a[i] = rand() % 1000;

    start = clock();
    for(i = 0; i < iter; i++)
        array_sum(a);
    end = clock();

    double duration = (end - start) / CLK_TCK;
    printf("Time taken is %g\n", duration/iter);
    return 0;
}