#include <stdio.h>

int factorial(int n){
  if(n <= 1){
    return 1;
  }else{
    return n * factorial(n-1);
  }
}

void fibbonaci(int x , int a , int b){
  if(x>0){
    printf("%d ",a);
    fibbonaci(x-1 , b, a+b);
  }  
}

int main(){
  int a;
  printf("Enter the number to find factorial : ");
  scanf("%d",&a);
  printf("factorial of given number is %d\n",factorial(a));
  printf("Fibbonaci is given by : ");
  fibbonaci(a,0,1);
  
  return 0;
}