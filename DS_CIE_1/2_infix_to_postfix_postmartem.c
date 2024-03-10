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
    return 1;
  if (op == '*' || op == '/')
    return 2;
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
      printf("##%c\n", *e);
    }
    else if (*e == '(')
    {
      push(*e);
      printf("__%c\n", *e);
    }
    else if (*e == ')')
    {
      while ((x = pop()) != '(')
      {
        postfix[pos++] = x;
        printf("$$%c\n", x);
      }
    }
    else
    {
      while (top != -1 && precedence(stack[top]) >= precedence(*e))
      {
        printf("!!!!!%d\n", top);
        postfix[pos++] = pop();
        printf("!!%s\n", stack[top]);
        printf("!%d\n", top);
      }
      printf("___%c\n", *e);
      push(*e);
    }
    e++;
  }

  while (top != -1)
  {
    printf("=!!%d\n", pos);
    postfix[pos++] = pop();
    printf("!!!%d\n", pos);
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
