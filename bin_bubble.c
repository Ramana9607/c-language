#include<stdio.h>
int binary_search(int n,int a[n])
{
	int key,low=0,high,mid;
	high=n-1;
	printf("enter key value=");
	scanf("%d",&key);
	while(low<high)
	{
		mid=(low+high)/2;
		if(key==a[mid])
		{
		printf("element found at position %d",mid);
		break;
	}
		else if(key<a[mid])
		high=mid-1;
		else if(key>a[mid])
		low=mid+1;
		else
		printf("element not found");
	}
}
int bubble_sort(int n,int a[n])
{
	int i,j,temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				
			}
		}
	}
	printf("the sorted array=");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	binary_search(n,a);
}
void main()
{
	int i,j,n,a[20],temp=0;
	printf("enter n value");
	scanf("%d",&n);
	printf("enter array elements=");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubble_sort(n,a);
	
}