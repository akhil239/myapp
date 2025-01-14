#include<stdio.h>
#include<stdlib.h>



struct Node
{   int data;
    struct Node *next;
    /* data */
};
int add_node(int data);
void traverse();
struct Node *ptr = NULL;

int main(){
    add_node(50);
    add_node(500);
    add_node(570);
    add_node(545);
    add_node(5370);
    printf("%d",ptr->data);
    traverse();
    return 0;
}
int del_node_pos(){
    
}
int add_node(int data){
    if(ptr == NULL){
        ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;
        printf("new node as created sccuessfully...");
        return 0;
    }else{
        struct Node *current = ptr;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = (struct Node *)malloc(sizeof(struct Node));
        current->next->data = data;
        current->next->next = NULL;
    }

}
void traverse(){
    struct Node *current = ptr;
    while (current != NULL)
    {   printf("\n%d",current->data);
        current = current->next;
        /* code */
    }
    

}