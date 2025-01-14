#include<stdio.h>
#include<stdlib.h>

struct Node
{   int data;
    struct Node *next;
    /* data */
};
int add_node(int data);
struct Node *ptr = NULL;

int main(){
    return 0;
    add_node(50);
}

int add_node(int data){
    if(ptr == NULL){
        ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        printf("new as created sccuessfully...");
    }

}
void traverse(){


}