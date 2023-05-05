//Infix to prefix                                                                                                                                                                              #include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maxsize 100
char s[maxsize];
int top=-1;
void infix_to_prefix(char exp[]);
void push(char x);
char peek();
char pop();
int icp(char op);
int isp(char op);
void main()
{
   char exp[100];
   printf("enter infix expression");
   scanf("%s",exp);
   infix_to_prefix(exp);
}
void infix_to_prefix(char exp[10])
{
    int i,l,j;
    char x,exp1[100];
    top=-1;
    push('#');
    l=strlen(exp);
    //printf("in infix_to_prefix fun len of string=%d\n",l);
    i=l-1;j=0;
    while(exp[i]!='\0')
    {
    if(isalnum(exp[i]))
    {
    //	printf(" in alnum=%c\n",exp[i]);
    exp1[j]=exp[i];
    j++;
    }
    else if(exp[i]==')')
    {
    //	printf(" in ')' %c \n",exp[i]);
    push(')');
    }
    else if(exp[i]=='(')
    {
    	//	printf(" in '(' %c \n",exp[i]);
    while(peek()!=')')
    {
    x=pop();
    exp1[j]=x;
    j++;
    }
    x=pop();
    }
    else
    {
    while((isp(peek()))>=(icp(exp[i])))
    {
    		//printf(" in isp icp comparision %c \n",exp[i]);
    x=pop();
    exp1[j]=x;
    j++;
    }
    push(exp[i]);
    }
    i--;
    }
    while(top>0)
    {
    x=pop();
    exp1[j]=x;
    j++;
    }
    exp1[j]='\0';
    strrev(exp1);
    puts(exp1);
}
int icp(char op)
{
if(op=='*'||op=='/')
return 2;
if(op=='+'||op=='-')
return 1;
if(op=='^')
return 4;
if(op==')')
return 5;
}
int isp(char op)
{
if(op=='+'||op=='-')
return 1;
if(op=='*'||op=='/')
return 2;
if(op=='^')
return 3;
if(op==')')
return 0;
if(op=='#')
return -1;
}
void push(char x)
{
if(top==maxsize-1)
{
printf("stack is full");
}
else
{
top++;
s[top]=x;
//printf("in push x=%c\n",s[top]);
}
}
char pop()
{
char x;
if(top==-1)
{
return '#';
}
else
{
x=s[top];
top--;
//printf("in pop x=%c\n",x);
return x;
}
}
char peek()
{
char x;
if(top==-1)
{
return '#';
}
else
{
x=s[top];
//printf("in peek x=%c\n",x);
return x;
}
}