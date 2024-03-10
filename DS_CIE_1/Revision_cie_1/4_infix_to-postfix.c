#include <stdio.h>
#include <ctype.h>
#define size 100
int top = -1;

char array_stack[size];

void push(char);
char pop();
void display();
int precedence(char);
void infixToPostfix(char[], char[]);
int main()
{
  char infix[size], postfix[size];
  printf("Enter the expression to convert into postfix : ");
  scanf("%[^\n]s", infix);
  infixToPostfix(infix, postfix);
  printf("The postfix expression is %s",postfix);

  return 0;
}

void push(char value)
{
  array_stack[++top] = value;
}

char pop()
{
  return array_stack[top--];
}
int precedence(char a)
{
  if (a == '*' || a == '/')
  {
    return 2;
  }
  else if (a == '+' || a == '-')
  {
    return 1;
  }
  else if (a == '^')
  {
    return 3;
  }
  return 0;
}
void infixToPostfix(char infix[], char postfix[])
{
  char e, x;
  int i =0;
  e = infix[i];
  int pos = 0;
  while (e != '\0')
  {
    if (isalnum(e)){
      postfix[pos++] = e;
    }else if(e == '('){
      push(e);
    }else if(e ==')'){
      while((x = pop()) != '('){
        postfix[pos++] = x;
      }
    }else {
      while(top != -1 && precedence(array_stack[top]) >= precedence(e)){
      postfix[pos++] = pop();
    }
    push(e);
  }
   e = infix[++i];
  }
  while (top != -1)
  {
    postfix[pos++] = pop();
  }
  postfix[pos++] = '\0';
  
}
