#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int val) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow");
        exit(0);
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow");
        exit(0);
    }
    return stack[top--];
}

int evaluate(char* postfix) {
    int i, x, y, result;
    for (i = 0; postfix[i] != '\0'; i++)
	 {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } 
		else {
            x = pop();
            y = pop();
            switch (postfix[i]) 
			{
                case '+':
                    push(y + x);
                    break;
                case '-':
                    push(y - x);
                    break;
                case '*':
                    push(y * x);
                    break;
                case '/':
                    push(y / x);
                    break;
                default:
                    printf("Invalid operator");
                    exit(0);
            }
        }
    }
    result = pop();
    return result;
}

int main() {
    char expr[MAX_SIZE];
    int res;
    printf("Enter postfix expression: ");
    gets(expr);
    res = evaluate(expr);
    printf("Result = %d", res);
    return 0;
}

