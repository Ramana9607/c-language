//program to perform inter polation search using functions
#include<stdio.h>
int interpolation_search(int n,int a[n],int key)
{
	int low,high,mid;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=low+(key-a[low])/(a[high]-a[low])*(high-low);
		if(a[mid]==key)
		{
			return mid;
		}
		else if(key<a[mid])
		{
			high=mid-1;
		}
		else if(key>a[mid])
		{
			low=mid+1;
		}
		else
		return -1;	
	}
}
 int main()
{
	int i,j,n,key,pst;
	printf("enter n value=");
	scanf("%d",&n);
	int a[n];
	printf("enter key value");
	scanf("%d",&key);
	printf("enter elements in the array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	pst=interpolation_search(n,a,key);
	if(a[pst]==key)
	{
		printf("element is found at position=%d",pst);
	}
	if(pst==-1)
	{
		printf("element not found");
	}
}