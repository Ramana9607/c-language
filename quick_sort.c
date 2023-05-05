#include<stdio.h>
int partition(int a[20],int low,int high);
void quick(int a[20],int low,int high);
void main()
{
	int a[20],low,high,i,j,n;
	printf("enter n value");
	scanf("%d",&n);
	printf("enter array elements");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	low=0;
	high=n-1;
	quick(a,low,high);
	printf("sorted array is=\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
}
void quick(int a[20],int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
		quick(a,low,j-1);
		quick(a,j+1,high);
		
	}
}
int partition(int a[20],int low,int high)
{
	int key,temp,i,j;
	key=a[low];
	i=low+1;
	j=high;
	do
	{
		while(i<=high && a[i]<key)
		i++;
		while(j>=low && a[j]>key)
		j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<=j);
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	return j;
}