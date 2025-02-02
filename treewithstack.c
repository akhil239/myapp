#include<stdio.h>
#include<stdlib.h>
extern long add_number(long a , long b);
int main(){
    long res = add_number(2,50);
    printf("%d",res);

    return 0;
}