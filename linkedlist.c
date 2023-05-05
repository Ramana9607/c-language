#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int d;
    struct Node *link;
}node;
node *head;
int insert_begin(int x)
{
    node *NNode=(node*)malloc(sizeof(node));
    if(head==NULL)
    {
        NNode->link=NULL;
    }
    else
    {
        NNode->link=head;
    }
    NNode->d=x;
    head=NNode;
    return x;
}
int insert_end(int x)
{
    node *NNode=(node*)malloc(sizeof(node));
    node *t;
    if(head==NULL)
    {
        NNode->d=x;
        NNode->link=NULL;
        head=NNode;
    }
    else
    {
        t=head;
        while(t->link!=NULL)
        t=t->link;
        
        NNode->d=x;
        NNode->link=NULL;
        t->link=NNode;
    }
    return x;
}
int insert_middle(int n, int x)
{
    node *NNode=(node*)malloc(sizeof(node));
    node *t;
    if(n==1)
    return insert_begin(x);
    else
    {
        int i=0;
        t=head;
        while(i<n-2&&t->link!=NULL)
        {
            t=t->link;
            i++;
        }
       
        
            NNode->link=t->link;
            t->link=NNode;
            NNode->d=x;
            return x;
        
    }
}
void display()
{
    node *t;
    t=head;
    while(t->link!=NULL)
    {
        printf("%d\t",t->d);
        t=t->link;
    }
    printf("%d\n",t->d);
}
int delete_begin()
{
    int x;
    if(head==NULL)
    return -1;
    else if(head->link==NULL)
    {
        x=head->d;
        free(head);
        head==NULL;
        return x;
    }
    else
    {
        x=head->d;
        node *t;
        t=head->link;
        free(head);
        head=t;
        t=NULL;
        return x;
    }
}
int delete_end()
{
    int x;
    if(head==NULL)
    return -1;
    else if(head->link==NULL)
    {
        x=head->d;
        free(head);
        head==NULL;
        return x;
    }
    else
    {
        node *t,*tp;
        t=head;
        while(t->link!=NULL)
        {
            tp=t;
            t=t->link;
        }
        x=t->d;
        tp->link=NULL;
        free(t);
        t=NULL;
        return x;
    }
}
int delete_middle(int n)
{
    int x;
    if(head==NULL)
    return -1;
    else
    {
        int i=0;
        node *t,*tp;
        t=head;
        while(i<n-1&&t->link!=NULL)
        {
            tp=t;
            t=t->link;
            i++;
        }
        if(i!=n-1)
        {
            return -2;
        }
        else
        {
            tp->link=t->link;
            x=t->d;
            free(t);
            t=NULL;
            tp=NULL;
            return x;
        }
    }
}
void main()
{
    int x,c,n;
    printf("\n1.Insert begin\t2.Insert End\t3.Insert Middle\t4.Delete Begin\t5.Delete End\t6.Delete Middle\t7.Display\t8.Exit\n");
    do{
        scanf("%d",&c);
    switch(c)
    {
        case 1: printf("Enter element: ");
                scanf("%d",&x);
                printf("%d is inserted at beginning\n",insert_begin(x));
                break ;
        case 2: printf("Enter element: ");
                scanf("%d",&x);
                printf("%d is inserted at ending\n",insert_end(x));
                break ;
        case 3:printf("Enter element and position: ");
                scanf("%d%d",&x,&n);
                printf("%d is inserted at %d\n",insert_middle(n,x),n);
                break ;
        case 4: printf("Deleted element is %d\n",delete_begin());
                break ;
        case 5: printf("Deleted element is %d\n",delete_end());
                break ;
        case 6: printf("Enter position: ");
                scanf("%d",&n);
                printf("Deleted element is %d\n",delete_middle(n));
                break ;
        case 7: display();
                break ;
        case 8: printf("Exiting......\n");
                break ;
        default: printf("Invalid choice\n");
    }
    }while(c!=8);
}