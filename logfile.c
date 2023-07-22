#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{

    int n,i,j,t,temp;
    clock_t start_end;
    double cpu_time_used;
    double time_taken;

    printf("enter the number of elements to be sorted:");
    scanf("%d",&n);

}

int arr[n];
srand(time(NULL));
printf("generating %d random numbers...\n",n);
for(i=0;i<n;i++)
{

    arr[i]=rand()%100+1;
}
start=clock();
for(i=0;i<n-1,i++)
{
    for(j=0;j<n-i-1;j++)
    {
        if (arr[j]>arr[j+1])
        {
    temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;
}
    }
}
end =clock();
cpu_time_used=((double)end-start))    //clocks_per_seconds
time_taken=((double)t);    //time in seconds
printf("sorted array:\n");
for(i=0;i<n;i++);
printf("%d",arr[i]);
FILE*fp;
fp=fopen("sorted")
