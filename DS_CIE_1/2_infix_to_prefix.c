#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 20

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void reverseString(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void infixToPrefix(char *infix, char *prefix) {
    char *e, x;
    int len = strlen(infix);
    int pos = 0;

    reverseString(infix);

    for (int i = 0; i < len; i++) {
        e = &infix[i];

        if (isalnum(*e)) {
            prefix[pos++] = *e;
        } else if (*e == ')') {
            push(*e);
        } else if (*e == '(') {
            while ((x = pop()) != ')') {
                prefix[pos++] = x;
            }
        } else {
            while (top != -1 && precedence(stack[top]) > precedence(*e)) {
                prefix[pos++] = pop();
            }
            push(*e);
        }
    }

    while (top != -1) {
        prefix[pos++] = pop();
    }

    prefix[pos] = '\0';
    reverseString(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("The prefix expression is: %s\n", prefix);

    return 0;
}
