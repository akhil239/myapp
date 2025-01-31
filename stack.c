#include<stdio.h>
#include<stdlib.h>
int n; // length
int *stack;
int top;
void push(int value){
    top = top+= 1;
    stack[top] = value;
}

int main(){
    n = 5;
    stack = (int *)malloc(n * sizeof(int));
    top = -1;
    push(5);
    push(89);
    printf("%d",stack[0]);
    printf("%d",stack[1]);
    return 0;
}