#include<stdio.h>
#include<stdlib.h>
int *createStack(int n){
    int *stack = (int *)malloc(n * sizeof(int));
    int top
    return stack;
}

int main(){
    int *stack = createStack(10);
    stack[0] = 10;
    printf("%d",stack[0]);
    return 0;
}