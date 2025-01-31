#include<stdio.h>
#include<stdlib.h>
int n; // number of eleement
int *stack; //globel stack pointer 
int top;//this show the top element in the stack 
//this function add element to the stack
int first;
void push(int value){
    top = top+= 1;//this will increment top by 1 so that we can use this to track stack element's
    stack[top] = value;//
}
//this function will remove element from stack
void pop(){
    
    top = top-=1;//this  subtract 1 from top 
    /*when we subtract 1 from the top the will become top - 1 
    for example stack have 5 element's
    so the top we be 4 when we subract 1 from top will be 3
    this will not going to remove that element from the stack but we are dicresing the stack 
    by using this code so that we overwrite that element after dicrseing the stack 
    we need to call push again this overwrite that element with new one*/
}
void queuepush(int value){
    stack[top] = value;
    top = top-=1;
}
void queuepop(){
    first -=1;
}

int main(){
    n = 5;//n = 5 length of this stack is 5
    stack = (int *)malloc(n * sizeof(int)); //this points to dynamic array this array can hold upot 5 elements
    top = -1;//if we don't use negitve number we start from inserting element's from 1 so  that's way we negitive number 
    first = -1;
    stack[top] = 5;
    stack[top-1] = 500;
    printf("%d",stack[-2]);
    
    // queuepush(5);//this will  add number; 5 to the stack
    // queuepush(89);// this will add number ; 8 to the stack
    // queuepop();// this will pop element from the stack by subtrating the top 
    // printf("%d",top);
    //this will prints element's persent in the stack
    // for(int i = n;i >= top;i--){
    //     printf("%d\n",stack[i]);
    // }
    return 0;
}