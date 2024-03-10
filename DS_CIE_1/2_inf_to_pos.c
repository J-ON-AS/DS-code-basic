#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char x)
{
  stack[++top] = x;
}

char pop()
{
  return stack[top--];
}

int precedence(char op)
{
  if (op == '+' || op == '-')
  {
    return 1;
  }
  else if (op == '*' || op == '/')
  {
    return 2;
  }
  else if (op == '^')
  {
    return 3;
  }
  return 0;
}

void infixToPostfix(char *infix, char *postfix)
{
  char *e, x;
  e = infix;
  int pos = 0;

  while (*e != '\0')
  {
    if (isalnum(*e))
    {
      postfix[pos++] = *e;
    } 
    else if (*e == '(')
    {
      push(*e);
    }
    else if (*e == ')')
    {
      while ((x = pop()) != '(')
      {
        postfix[pos++] = x;
      }
    }
    else
    {
      while (top != -1 && precedence(stack[top]) >= precedence(*e))
      {
        postfix[pos++] = pop();
      }
      push(*e);
    }
    e++;
  }

  while (top != -1)
  {
    postfix[pos++] = pop();
  }
  postfix[pos] = '\0';
}

int main()
{
  char infix[20], postfix[20];
  printf("Enter the infix expression: ");
  scanf("%s", infix);

  infixToPostfix(infix, postfix);
  printf("The postfix expression is: %s\n", postfix);
  return 0;
}
