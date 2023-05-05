#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
 

 int q[MAXSIZE],f=-1,r=-1;

 void insert(int ele)
{
	if(r==-1&&f==-1)
	{
		r++;
		f++;
		q[r]=ele;
	}
	else if ((f==0&&r==MAXSIZE-1)||(f==r+1))
	
		{
			printf("queue is full");
		}
	
	else if(f!=0&&r==MAXSIZE-1)
	{
		r=0;
		q[r]=ele;
	}
	else
	{
		r++;
		q[r]=ele;
	}
}
int deletion()
{ 
	int x;
	x=q[f];
	if(f==-1&&r==-1)
	{
		return -1;
	}
	else if(f==r)
	{
		f=-1;
		r=-1;
	}
	else if(f==MAXSIZE-1)
	{
		f=0;
	}
	else
	{
		f++;
	}
	return x;
}
void display()
{
	int i;
	if(f<r)
	{
		for(i=f;i<=r;i++)
		printf("%d\t",q[i]);
	}
	else
	{
		for(i=f;i<=MAXSIZE-1;i++)
		{
			printf("%d",q[i]);
		}
	}
}
 void main()
 {
 	int ele,i,choice;
 	while(1)
 	{
 		printf("enter your choice");
 		printf("\n1.insert\n2.deletion\n3.display\n4.exit\n");
 		scanf("%d",&choice);
 		switch(choice)
 		{
 			case 1: printf("enter the element=");
 					scanf("%d",&ele);
 					insert(ele);
 					break;
 					
 			case 2:ele=deletion();
 					if(ele==-1)
 					printf("queue is empty");
 					else
 					printf("poped element is %d\n",ele);
 					break;
 					
 			case 3:display();
			 break;
			 case 4:exit(0);
			 default:
			 printf("invalid choice");			
		 }
	 }
 }
