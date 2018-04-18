#include<stdio.h>
int main()
{
	int a[20],b[20], s[20], w[20],t[20],i, k, n, tema;
	float wavg, tavg;
	arintf("Enter the number of PROCESS  in the queue --- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i] = i;
		printf("Enter the Burst Time for Process  %d --- ", i);
		scanf("%d",&b[i]);
		printf("teacher/student Process (0/1) ? --- ");
		scanf("%d", &s[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(k=i+1;k<n;k++)
		{
			if(s[i] > s[k])
			{
				tema=a[i];
				a[i]=a[k];
				a[k]=tema;
				
				tema=b[i];
				b[i]=b[k];
				b[k]=tema;
				
				tema=s[i];
				s[i]=s[k];
				s[k]=tema;
			}
		}
	}
	wavg = w[0] = 0;
	tavg = t[0] = b[0];
	for(i=1;i<n;i++)
	{
		w[i] = w[i-1] + b[i-1];
		t[i] = t[i-1] + b[i];
		wavg = wavg + w[i];
		tavg = tavg + t[i];
	}
	printf("\nPROCESS\t\t TEACHER/STUDENT PROCESS  \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
	
	for(i=0;i<n;i++)
	{
		printf("\n%d \t\t %d \t\t %d \t\t %d \t\t\t %d ",a[i],s[i],b[i],w[i],t[i]);
	}

	printf("\nAverage Waiting Time is --- %f",wavg/n);
	printf("\nAverage Turnaround Time is --- %f",tavg/n);

	return 0;
}
