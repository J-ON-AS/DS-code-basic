#include<stdio.h>
#include<string.h>

#define max 100
int top = -1;
char stack_string[max];
void push(char value){
  if(top >= max -1){
    printf("Stack overflow enter small string!!");
  }
  else{
    stack_string[++top] = value;
  }
}
int pop(){
  if(top<0){
    printf("Stack Underflow!!!");
  }
  else{
    return stack_string[top--];
  }
}
int main(){
  char str[max] ;
  printf("Enter the string to be reversed : ");
  scanf("%[^\n]s",str);
  for (int i = 0; i < strlen(str); i++)
  {
    push(str[i]);
  }
  for (int i = 0; i < strlen(str); i++)
  {
    str[i] = pop();
  }
  printf("The reversed string is : %s",str);
  
}