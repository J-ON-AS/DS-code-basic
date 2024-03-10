#include <stdio.h>
// void printFun(int test)
// {
//   if (test < 1)
//     printf("_");
//   else
//   {
//     printf("*");
//     printf("%d", test);
//         printFun(test - 1); // statement 2
//     printf("%d*", test);
//     printf("");
//   }
// }
// int main()
// {
//   int test = 3;
//   printFun(test);
// }

void fibonacci(int n, int a, int b) {
    if (n > 0) {
        printf("%d ", a); // Print the current Fibonacci number
        fibonacci(n - 1, b, a + b); // Recursively call fibonacci function with updated values
    }
}

int main() {
    int n = 10; // Define the number of elements in the series

    printf("Fibonacci Series up to %d terms: ", n);
    fibonacci(n, 0, 1); // Start the series with 0 and 1

    return 0;
}