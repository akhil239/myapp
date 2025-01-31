#include<stdio.h>
#include<stdlib.h>
int n; // number of eleement
int *stack; //globel stack pointer 
int top;//this show the top element in the stack 
//this function add element to the stack
void push(int value){
    top = top+= 1;
    stack[top] = value;
}
//this function will remove element from stack
void pop(){
    
    top = top-=1;//this  
}

int main(){
    n = 5;//n = 5 length of this stack is 5
    stack = (int *)malloc(n * sizeof(int)); //this points to dynamic array this array can hold upot 5 elements
    top = -1;
    push(5);
    push(89);
    pop();
    // printf("%d",top);
    for(int i = 0;i <= top;i++){
        printf("%d",stack[i]);
    }
    return 0;
}