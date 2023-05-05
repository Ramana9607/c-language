#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

void push(int item) {
    if (top == MAXSIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = item;
    
}

int pop() {
    int item;
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    item = stack[top];
    top--;
    return item;
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

int main() {
    int choice, item;
    while (1) {
        printf("\n1. Push\n");
        printf("2. display\n");
        printf("3. pop\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;
            case 3:
                item = pop();
                if (item != -1)
                    printf("Popped item is %d\n", item);
                break;
            case 2:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
