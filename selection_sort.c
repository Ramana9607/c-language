#include<stdio.h>
int sel_sort(int n,int a[n])
{
	int i,j,min,temp=0;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	printf("sorted array is ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
int main()
{
	int i,j,a[20],n;
	printf("enter n value");
	scanf("%d",&n);
	printf("enter array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sel_sort(n,a);
}